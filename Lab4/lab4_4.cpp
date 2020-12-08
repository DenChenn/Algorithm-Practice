#include <bits/stdc++.h>
using namespace std;
#define N 800
#define M 1001
int dis[N];
int vx[N];
int vy[N];
bool edgeEx[N][N];
struct Edge{
    Edge(int from, int to, int w):from(from), to(to), w(w){}
    int from;
    int to;
    int w;
};

bool operator < (Edge& a, Edge& b){
    return a.w < b.w;
}
vector<Edge> E;
vector<Edge> ans;

void init(){
    for(int i = 0;i < N;i++){
        dis[i] = -1;
    }
    memset(edgeEx, false, N*N);
    E.clear();
    ans.clear();
}

void Kruskal(){
    for(auto e:E){
        
    }
} 

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        int n, m, a, b, distance;
        cin >> n;
        for(int i = 1;i <= n;i++){  //start from building 1
            cin >> vx[i] >> vy[i];
        }
        cin >> m;
        for(int i = 0;i < m;i++){
            cin >> a >> b;
            edgeEx[a][b] = true;
            dis[a] -= 1;
            dis[b] = a;
        }
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(edgeEx[i][j])
                    continue;
                distance = (vx[i] - vx[j])*(vx[i] - vx[j]) + (vy[i] - vy[j])*(vy[i] - vy[j]);
                E.push_back(Edge(i, j, distance));
            }
        }
        sort(E.begin(), E.end());

    }
}

