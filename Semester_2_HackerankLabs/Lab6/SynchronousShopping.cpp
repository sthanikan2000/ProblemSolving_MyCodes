#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

struct graph{
    int u;
    int v;
    int weight;
};
struct Check_dist{
    bool operator () (graph s1, graph s2){
        int d1=s1.weight,d2=s2.weight;
        return d1>=d2;
    }
};

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

vector<vector<int>> d;
int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {
    d.assign(n,vector<int>(1<<k,INT_MAX));
    int foo=0;
    vector<int> canbuy(n,0);
    for(int i=0; i<n; i++){
        stringstream StrS;
        StrS<<centers[i];
        int num;
        int cnt=0;
        while(StrS>>num){
            cnt++;
            if(cnt==1)
                continue;
            canbuy[i]=canbuy[i]|(1<<(num-1));
        }
    }
    foo=canbuy[0];
    vector<vector<pair<int,int> > > adj(n);       
    for(int i=0; i<int(roads.size()); i++){
        int u=roads[i][0]-1;
        int v=roads[i][1]-1;
        int w=roads[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    d[0][foo]=0;

    priority_queue<graph,vector<graph>,Check_dist> Pro_q;
    Pro_q.push({0,foo,0});
    while(!Pro_q.empty()){
        int node=Pro_q.top().u;
        foo=Pro_q.top().v;
        int weight=Pro_q.top().weight;
        Pro_q.pop();
        if(weight!=d[node][foo])
            continue;
        for(auto it: adj[node]){
            int v=it.first;
            int w=it.second;
            if(d[node][foo]!=INT_MAX&&d[v][canbuy[v]|foo]>d[node][foo]+w){
                d[v][canbuy[v]|foo]=d[node][foo]+w;
                Pro_q.push({v,canbuy[v]|foo,d[v][canbuy[v]|foo]});        
            }
        }
    }
    int time=INT_MAX;
    for(int i=0; i<(1<<k); i++){
        for(int j=0; j<(1<<k); j++){
            if((i|j)==(1<<k)-1)
            time=min(time,max(d[n-1][i],d[n-1][j]));                    
        }
    }
    return time;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

    fout << res << "\n";

    fout.close();

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