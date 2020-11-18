#include <bits/stdc++.h>
using namespace std;
#define inf 100001
using Edge = pair<int, int>;
#define w first
#define idx second
int vn;
int dist[20001]; //記錄從起點到每一個點的最短路徑
vector<Edge> adj[20001]; 

int r, S, B;

void init() {
    for(int i = 0;i < vn;i++){
        adj[i].clear();
    }
}

void dijkstra(int s){
    vector<bool> vis(vn, false);
    fill_n(dist, 20001, inf);
    dist[s] = 0;//出發點要設成 0
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; //先比 w 也就是 first
    pq.emplace(0, s); //weight = 0的start點放進去了

    while(!pq.empty()){
        int u = pq.top().idx;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;

        for(auto v : adj[u]){
            if(dist[v.idx] > dist[u] + v.w){ //經過這個 u 點再到 v, 比之前到v的最近狀況還要近
                dist[v.idx] = dist[u] + v.w;
                pq.emplace(dist[v.idx], v.idx);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int time;
    cin >> time;
    while(time--){
        init();
        int from, dst, wei;
        cin >> vn >> r >> S >> B;
        for(int i = 0;i < r;i++){
            cin >> from >> dst >> wei;
            adj[from].push_back(Edge(wei, dst));
            adj[dst].push_back(Edge(wei, from));
        }
        if(r == 0){
            cout << "YOU DIED" << endl;
            continue;
        }
        dijkstra(S);

        if(dist[B] == 100001)
            cout << "YOU DIED" << endl;
        else
            cout << dist[B] << endl;
    }
    return 0;
}