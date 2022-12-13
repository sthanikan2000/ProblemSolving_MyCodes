#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<int> shortestReach(int n, vector<vector<vector<int>>> adj_u, int s) {
    //----INITIALIZE-SINGLE-SOURCE----------
    vector<int> sp;
    for (int i=0;i<n;i++){
        sp[i]=-1;
    }
    sp[s-1]=0;
    //--------------------------------------

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vector<vector<int>> adj=adj_u[u-1];

        for(int k=0;k<adj.size();k++){
            int v=adj[k][0];
            int w=adj[k][1];

            if(sp[v-1]==-1)[
                sp[v-1]=w;
                q.push(v);
            ]
            else{
                if(sp[v-1]>sp[u-1]+w){
                    sp[v-1]=sp[u-1]+w;
                    q.push(v);
                }
            }
        }  
    }
    return sp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        //vector<vector<int>> edges(m);
        vector<vector<vector<int>>> adj_u(n);

        for (int i = 0; i < m; i++) {
            //edges[i].resize(3);
            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));
            int u;
            vector<int> temp;
            for (int j = 0; j < 3; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);
                if(j==0){
                    u=edges_row_item;
                    continue;
                }
                temp.push_back(edges_row_item);
                //edges[i][j] = edges_row_item;
            }
            adj_u[u-1].push_back(temp);
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = shortestReach(n, adj_u, s);

        for (size_t i = 0; i < result.size(); i++) {
            if(i!=(s-1)){
                fout << result[i];

                if (i != result.size() - 1) {
                    fout << " ";
                }

            }
            
        }

        fout << "\n";
    }

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
