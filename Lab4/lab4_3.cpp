#include <bits/stdc++.h>
#define N 100001
#define inf 5000000001
#define need first
#define idx second
using namespace std;
using Edge = pair<int, int>;
int open[N];
int close[N];
int take[N];
vector<Edge> adj[N];
long long dist[N];
int nj, nr;
long long now[N];

struct Cmp {
    bool operator() (Edge& a, Edge& b){
        int need;
        int u = a.idx;
        int min_need1 = 0;
        int min_need2 = 0;
        for(auto v:adj[u]){
            if(open[v.idx] - (now[u] % (open[v.idx] + close[v.idx])) >= take[v.idx]) //開著而且剩下的時間夠通過
                need = take[v.idx];
            else if(open[v.idx]- (now[u] % (open[v.idx] + close[v.idx])) >= 0) //開著但是剩下的時間不夠通過
                need = open[v.idx] - (now[u] % (open[v.idx] + close[v.idx])) + close[v.idx] + take[v.idx];
            else //現在還關著
                need = close[v.idx] - (now[u] % (open[v.idx] + close[v.idx]) - open[v.idx]) + take[v.idx];
            if(min_need1 > need)
                min_need1 = need;
        }

        u = b.idx;
        for(auto v:adj[u]){
            if(open[v.idx] - (now[u] % (open[v.idx] + close[v.idx])) >= take[v.idx]) //開著而且剩下的時間夠通過
                need = take[v.idx];
            else if(open[v.idx]- (now[u] % (open[v.idx] + close[v.idx])) >= 0) //開著但是剩下的時間不夠通過
                need = open[v.idx] - (now[u] % (open[v.idx] + close[v.idx])) + close[v.idx] + take[v.idx];
            else //現在還關著
                need = close[v.idx] - (now[u] % (open[v.idx] + close[v.idx]) - open[v.idx]) + take[v.idx];
            if(min_need2 > need)
                min_need2 = need;
        }
        return min_need1 > min_need2;
    }
};

void init(){
    for(int i = 0;i < nj+1;i++)
        adj[i].clear();
}

void spfa(int s){
    fill_n(dist, N, inf);
    fill_n(now, N, 0);
    dist[s] = 0;
    vector<bool> vis(nj+1, false); //從一開始所以要多一
    priority_queue<Edge, vector<Edge>, Cmp<Edge>> pq;
    pq.emplace(0, s);
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
                cout << "u: " << u << " v: " << v.idx << endl;
                now[v.idx] = now[u] + need;
                dist[v.idx] = dist[u] + need;
                pq.emplace(need, v.idx);
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