#include <bits/stdc++.h>
using namespace std;
using Edge = pair<int,int>;
#define idx first 
#define t second 
#define N 1001
#define inf 1000001
vector<Edge> adj[N];
int dist[N];
int spcl, w;

void init(){
    for(int i = 0;i < N;i++)
        adj[i].clear();
}

bool spfa(int s){
    fill_n(dist, spcl, inf);
    dist[s] = 0;
    vector<int> cnt(spcl, 0);
    vector<bool> inq(spcl, false);
    queue<int> q;
    q.push(s);
    inq[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(auto v : adj[u]){
            if(dist[v.idx] > dist[u] + v.t){
                if(++cnt[v.idx] >= spcl)
                    return true;
                dist[v.idx] = dist[u] + v.t;
                if(!inq[v.idx]){
                    inq[v.idx] = true;
                    q.push(v.idx);
                }
            }
        }
    }
    return false;
}

int main() {
    int time;
    cin >> time;
    int a, b, tempt;
    while(time--){
        init();
        cin >> spcl >> w;
        for(int i = 0;i < w;i++){
            cin >> a >> b >> tempt;
            adj[a].push_back(Edge(b, tempt));
        }
        if(spfa(0))
            cout << "This is the choice of Steins;Gate" << endl;
        else
            cout << "El Psy Kongroo" << endl;
        
    }
}