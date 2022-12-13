#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj(1000002);
bool valid[1000002]={false};
int deg[1000002]={0};
int n,k;
set <int >q;
set <int > :: iterator it;
int main() {
    int i,j,x,y;
    cin>>n;
    while(n--){
        cin>>k>>x;
        valid[x]=true;
        for(j=1;j<k;j++)
            {
            cin>>y;
            deg[y]++;
            valid[y]=1;
            adj[x].push_back(y);
            x=y;
        }
        
    }
    for(i=0;i<1000001;i++)
        if(valid[i]&&deg[i]==0)
            q.insert(i);
    while(q.size()!=0){
        it=q.begin();
        cout<<*it<<" ";
        x=*it;
        q.erase(it);
        for(i=0;i<adj[x].size();i++)
        {
            deg[adj[x][i]]--;
            if( deg[adj[x][i]]==0)
                q.insert(adj[x][i]);
        }
    }
    return 0;
}
