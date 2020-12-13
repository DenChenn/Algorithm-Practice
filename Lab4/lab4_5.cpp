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
    void init(int n){
        for(int i = 1;i <= n;i++)
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
int m;

bool Cmp(Edge& e1, Edge& e2){
    return e1.w < e2.w;
}

int Kruskal(int i, int j){
    int cnt = 0;
    int fir = 10001;
    int las = -1;
    for(int x = i;x <= j;x++){
        int from = E[x].from;
        int to = E[x].to;
        if(!D.same(from, to)){
            if(fir > E[x].w)
                fir = E[x].w;
            if(las < E[x].w)
                las = E[x].w;
            cnt++;
            D.un(from, to);
        }
    }
    //cout << "cnt: " << cnt << endl;
    if(cnt != (vn - 1))
        return -1;
    else
        return las - fir;
}

int solve(){
    int block = vn - 1, ans;
    m = 10001;
    bool find = false;
    
    while(block <= en){
        for(int i = 0;i <= en-block;i++){
            D.init(vn);
            //cout << "i: " << i << " j: " << j << endl;
            ans = Kruskal(i, i+block-1);
            if(ans != -1){
                if(m > ans)
                    m = ans;
                find = true;
                //cout << "inin" << endl;
            }
        }
        if(find){
            break;
        }
        else{
            m = 10001;
            block++;
            continue;
        }
    }
    if(m != 10001){
        return m;
    }
    else
        return -1;
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t, eq;
    cin >> t;
    while(t--){
        E.clear();
        cin >> vn >> en;
        D.init(vn);
        for(int i = 1;i <= en;i++){
            Edge e;
            cin >> e.from >> e.to >> e.w;
            E.push_back(e);
        }
        int cnt;
        sort(E.begin(), E.end(), Cmp);
        cout << solve() << endl;     
    }
}