#include <bits/stdc++.h>
using namespace std;
using Point = pair<int,int>;
#define N 800
#define M 1001
int vx[N];
int vy[N];
bool edgeEx[N][N];
struct Edge{
    Edge(int from, int to, int w):from(from), to(to), w(w){}
    int from;
    int to;
    int w;
};
bool Cmp (Edge& a, Edge& b){
    return a.w < b.w;
}

struct disSet{
    int dis[N];
    void init(){
        for(int i = 0;i < N;++i)
            dis[i] = i;
    }

    int find(int v){
        if(dis[v] == v)
            return v;
        return dis[v] = find(dis[v]);
    }

    bool same(int a, int b){
        return find(a) == find(b);
    }

    void un(int a, int b){
        dis[find(a)] = find(b);
    }
};

vector<Edge> E;
vector<Point> ans;
disSet D;

void init(){
    memset(edgeEx, false, N*N);
    E.clear();
    ans.clear();
}

int Kruskal(){
    sort(E.begin(), E.end(), Cmp);
    int cnt = 0;
    for(auto e:E){
        if(!D.same(e.from, e.to)){
            cnt++;
            D.un(e.from, e.to);
            ans.push_back(Point(e.from, e.to));
        }
    }
    return cnt;
} 

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        D.init();
        int n, m, a, b, distance, cnt;
        cin >> n;
        for(int i = 1;i <= n;i++){  //start from building 1
            cin >> vx[i] >> vy[i];
        }
        cin >> m;
        for(int i = 0;i < m;i++){
            cin >> a >> b;
            edgeEx[a][b] = true;
            D.un(a,b);
        }
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(edgeEx[i][j])
                    continue;
                distance = (vx[i] - vx[j])*(vx[i] - vx[j]) + (vy[i] - vy[j])*(vy[i] - vy[j]);
                E.push_back(Edge(i, j, distance));
            }
        }
        
        cnt = Kruskal();
        cout << cnt << endl;
        if(cnt != 0){
            for(auto p:ans)
                cout << p.first << " " << p.second << endl;
        }
}
    return 0;
}

