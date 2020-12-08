#include <bits/stdc++.h>
using namespace std;
#define N 101
struct Edge{
    int from;
    int to;
    int w;
};
struct disSet{
    int dis[N];
    void init(){
        for(int i = 0;i < N;i++)
            dis[i] = i;
    }

    int find(int a){
        if(dis[a] == a)
            return a;
        return dis[a] = find(dis[a]);
    }

    bool same(int a, int b){
        return find(a) == find(b);
    }

    void un(int a, int b){
        dis[find(a)] = find(b);
    }
};
vector<Edge> E;
disSet D;
int vn, en;
int fir, las;

bool Cmp(Edge& e1, Edge& e2){
    return e1.w < e2.w;
}

int Kruskal(){
    sort(E.begin(), E.end(), Cmp);
    int cnt = 0;
    fir = 10001;
    las = -1;
    for(auto a: E){
        if(!D.same(a.from, a.to)){
            if(a.w > las)
                las = a.w;
            if(a.w < fir)
                fir = a.w;
            cnt++;
            D.un(a.from, a.to);
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
        E.clear();
        D.init();
        cin >> vn >> en;
        for(int i = 1;i <= en;i++){
            Edge e;
            cin >> e.from >> e.to >> e.w;
            E.push_back(e);
        }
        int cnt;
        cnt = Kruskal();
        if(cnt == vn-1){
            cout << "las: " << las << endl;
            cout << "fir: " << fir << endl;
            cout << las-fir << endl;
        }
        else
            cout << -1 << endl;
    }
}