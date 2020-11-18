#include <bits/stdc++.h>
#define N 10001
#define inf 5000000001
#define cost first
#define idx second
using namespace std;
using Edge = pair<int, int>;
int open[100001];
int close[100001];
int take[100001];
vector<Edge> adj[N];
long long dist[N];
int nj, nr;
long long now[N];

void init(){
    for(int i = 0;i < nj+1;i++)
        adj[i].clear();
}

void spfa(int s){
    fill_n(dist, N, inf);
    fill_n(now, N, 0);
    dist[s] = 0;
    vector<bool> vis(nj+1, false); //從一開始所以要多一
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.emplace(open[s]+close[s], s);
    int need = 0; // 到下一個點所需要的時間

    while(!pq.empty()){
        int u = pq.top().idx;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;

        for(auto v:adj[u]){
            if(open[v.idx] - (now[u] % (open[v.idx] + close[v.idx])) >= take[v.idx]) //開著而且剩下的時間夠通過
                need = take[v.idx];
            else if(open[v.idx]- (now[u] % (open[v.idx] + close[v.idx])) >= 0) //開著但是剩下的時間不夠通過
                need = open[v.idx] - (now[u] % (open[v.idx] + close[v.idx])) + close[v.idx] + take[v.idx];
            else //現在還關著
                need = close[v.idx] - (now[u] % (open[v.idx] + close[v.idx]) - open[v.idx]) + take[v.idx];
            
            if(dist[v.idx] > dist[u] + need){
                now[v.idx] = now[u] + need;
                dist[v.idx] = dist[u] + need;
                pq.emplace(open[v.idx]+close[v.idx], v.idx);
            }
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int time;
    int u, v, x, y, t;
    int start, end;
    cin >> time;
    while(time--){
        cin >> nj >> nr >> start >> end;
        for(int i = 0;i < nr;i++){
            cin >> u >> v >> x >> y >> t;
            adj[u].push_back(Edge(x+y, v));
            open[v] = x;
            close[v] = y;
            take[v] = t;
        }
        spfa(start);
        cout << dist[end] << endl;
    }
}