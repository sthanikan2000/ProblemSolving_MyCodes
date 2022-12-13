#include <bits/stdc++.h>
using namespace std;

int main () {
    //since n<=10000
    vector<int> adjU[10001], u_of_v[10001];
    int indeg[10001];
    int visited[10001];
    int ranks[10001];
    long long total[10001];
    int n, m;
    cin >> n >> m;

    memset(indeg, 0, (n + 1) * sizeof(int));
    adjU[0].push_back(1);
    u_of_v[1].push_back(0);
    indeg[1] = 1;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adjU[u].push_back(v);
      u_of_v[v].push_back(u);
      indeg[v]++;
    }

    stack<int> stck;
    stck.push(0);
    memset(visited, 0, (n + 1) * sizeof(int));
    visited[0] = 1;
    while (!stck.empty()) {
      int v = stck.top();
      stck.pop();

      for (long unsigned int i = 0; i < adjU[v].size(); i++)
        if (!visited[adjU[v][i]]) {
          stck.push(adjU[v][i]);
          visited[adjU[v][i]] = 1;
        }
    }

    if (!visited[n]) {
      cout << 0 << endl;
      return 0;
    }

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        for (long unsigned int j = 0; j < adjU[i].size(); j++)
          indeg[adjU[i][j]]--;
      }
    }

    int count = 0;
    stack<int> topo;

    for (int i = 0; i <= n; i++) {
      int j;
      for (j = 0; j <= n; j++)
        if (visited[j] && indeg[j] == 0)
          break;
      if (j > n) {
        cout << "INFINITE PATHS" << endl;
        return 0;
      } else {
        topo.push(j);
        ranks[count++] = j;
        if (j == n)
          break;

        indeg[j] = -1;
        for (long unsigned int k = 0; k < adjU[j].size(); k++)
          indeg[adjU[j][k]]--;
      }
    }

    memset(total, 0, (n + 1) * sizeof(long long));
    total[n] = 1;
    for (int i=count - 1;i>=0;i--)
    {
        int r = ranks[i];
        for (long unsigned int j = 0; j < u_of_v[r].size(); j++)
          if (visited[u_of_v[r][j]]) {
            total[u_of_v[r][j]] = (total[u_of_v[r][j]] + total[r]) % 1000000000;
          }
    }
    cout << total[0] << endl;
    return 0;
}