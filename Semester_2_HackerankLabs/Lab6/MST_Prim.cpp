#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();


void primsAlgo(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> graph[n];
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int start;
    cin >> start;
    start--;

    vector<int> parent(n, -1);
    vector<int> distance(n, INF);
    vector<bool> visited(n, false);
    
    // Select the first node & set it as 0
    distance[start] = 0;

    // w, v=> pq
    // This is a min heap, contains the lowest edges
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, start));

    int mstCost = 0;
    while (!pq.empty()){
        int curWeight = pq.top().first;
        int fromVertex = pq.top().second;
        pq.pop();
        
        if (visited[fromVertex]) continue;

        visited[fromVertex] = true;
        mstCost += curWeight;

        for (auto edge: graph[fromVertex]){
            int weight = edge.second;
            int toVertex = edge.first;
            
            if (!visited[toVertex] && distance[toVertex] > weight){
                pq.push(make_pair(weight, toVertex));
                distance[toVertex] = weight;
                parent[toVertex] = fromVertex;
            }
        }
    }

    std::cout <<mstCost << endl; 

}

int main(){
    primsAlgo();
    return 0;
}