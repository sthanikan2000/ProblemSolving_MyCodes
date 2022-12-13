#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


struct Edge { int u,v,w; }; 
//edge of a graph
//u-->from,v-->to,w-->weight

bool cus_compare(Edge x,Edge y){
    if(x.w==y.w){
        //if x.w==y.w then 
        //Choose the edge that minimizes the sum of u+v+w
        return (x.u+x.v<y.u+y.v);
    }
    else{
        //else min w
        return (x.w<y.w);
    }
}

int find_set_rep(int i, int* parent_arr){
    if((i-1)==parent_arr[i-1]) 
        //if set rep is same as node called
        return i;
    else 
        //search for the set rep recursively
        return find_set_rep(parent_arr[i-1]+1, parent_arr); 
}

int kruskals(int g_nodes,int g_edges, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<Edge> graph(g_edges);
    //we first take the full graph implementation in to a vector of edges
    for(int i=0;i<g_edges;i++){
        graph[i].u = g_from[i];
        graph[i].v = g_to[i];
        graph[i].w = g_weight[i];
    }
    
    sort(graph.begin(),graph.end(),cus_compare);
    
    int* parent = (int*)malloc(g_nodes* sizeof(int));
    for (int i=0;i<g_nodes; i++){
        //set representative of each nodes {0 to (g_nodes-1)} first assign as nodes itself 
        //where original nodes actually {1 to g_nodes}
        parent[i] = i;
    }
    
    int w=0; //weight of MST 
    
    for (int i=0;i<g_edges;i++){
        
        //find the set representative of vertex u
        int rep_u = find_set_rep(graph[i].u,parent);
        //find the set representative of vertex v
        int rep_v = find_set_rep(graph[i].v,parent);
        
        if(rep_u != rep_v){
            //if both are equal then they are in same set 
            //because there will be unique representative for each set
            //hence they are not equal then when connect them it will not form a cycle in set
            w += graph[i].w;

            //union the sets and form a new rep for both set
            parent[rep_u-1] = parent[rep_v-1];
        }
    }
    return w;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_edges, g_from, g_to, g_weight);

    cout<<res;

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
