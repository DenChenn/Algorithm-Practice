#include <bits/stdc++.h>
using namespace std;
#define N 10001
#define inf 5000000001
struct Edge{
    Edge(int a, int b, int c, int d) : idx(a), open(b), close(c), take(d){};
    int idx;
    int open;
    int close;
    int take;
};

vector<Edge> adj[N];
long long dist[N];
int nj, nr;
int now[N];

void init(){
    for(int i = 0;i < nj;i++)
        adj[i].clear();
}

void spfa(int s){
    fill_n(dist, N, inf);
    fill_n(now, N, 0);
    dist[s] = 0;
    vector<bool> inq(nj+1, false); //從一開始所以要多一
    queue<int> q;
    q.push(s);
    inq[s] = true;
    int need = 0; // 到下一個點所需要的時間

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;

        for(auto v:adj[u]){
            if(v.open - (now[u] % (v.open + v.close)) >= v.take) //開著而且剩下的時間夠通過
                need = v.take;
            else if(v.open - (now[u] % (v.open + v.close)) >= 0) //開著但是剩下的時間不夠通過
                need = v.open - (now[u] % (v.open + v.close)) + v.close + v.take;
            else //現在還關著
                need = v.close - (now[u] % (v.open + v.close) - v.open) + v.take;
            
            if(dist[v.idx] > dist[u] + need){
                now[v.idx] = now[u] + need;
                dist[v.idx] = dist[u] + need;
                if(!inq[v.idx]){
                    inq[v.idx] = true;
                    q.push(v.idx);
                }
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
            adj[u].push_back(Edge(v, x, y, t));
        }
        spfa(start);
        cout << dist[end] << endl;
    }
}