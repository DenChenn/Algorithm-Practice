#include <bits/stdc++.h>
#define N 100001
using namespace std;
struct Edge{
    Edge(int a, int b, int c, int d){
        idx = a;
        open = b;
        close = c;
        take = d;
    }
    int idx;
    int open;
    int close;
    int take;
};
vector<Edge> adj[N];
long long dist[N];
int nj, nr;

struct Cmp {
    bool operator() (Edge& a, Edge& b){
        return (dist[a.idx] > dist[b.idx]);
    }
};

void init(){
    for(int i = 0;i < nj+1;i++)
        adj[i].clear();
}

void spfa(int s){
    fill_n(dist, N, INT_MAX);
    dist[s] = 0;
    vector<bool> vis(nj+1, false); //從一開始所以要多一
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    pq.emplace(s, 0, 0, 0);
    pq.push(Edge(s,0,0,0));

    while(!pq.empty()){
        int u = pq.top().idx;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;

        for(auto v:adj[u]){
            if(v.take > v.open)
                continue;
            int mod = dist[u] % (v.open + v.close), more;

            if (mod + v.take <= v.open)
                more = 0;
            else
                more = v.open + v.close - mod;
            
            if(dist[v.idx] > dist[u] + v.take + more){
                dist[v.idx] = dist[u] + v.take + more;
                pq.push(Edge(v.idx, v.open, v.close, v.take));
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
        init();
        cin >> nj >> nr >> start >> end;
        for(int i = 0;i < nr;i++){
            cin >> u >> v >> x >> y >> t;
            adj[u].push_back(Edge(v,x,y,t));
        }
        spfa(start);
        cout << dist[end] << endl;
    }
    return 0;
}