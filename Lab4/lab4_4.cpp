#include <bits/stdc++.h>
using namespace std;
#define N 800
#define M 1001
int dis[N];
int vx[N];
int vy[N];
bool edgeEx[N][N];
struct Edge{
    int from;
    int to;
    int w;
}
bool operator < (Edge& a, Edge& b){
    return a.w < b.w;
}
vector<Edge> E;

void init(){
    for(int i = 0;i < N;i++){
        dis[i] = -1;
        edgeEx[i] = false;
    }
    E.clear();
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> vx[i] >> vy[i];
        }
        cin >> m;

    }
}

