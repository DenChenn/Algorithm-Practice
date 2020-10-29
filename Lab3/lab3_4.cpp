#include <bits/stdc++.h>
using namespace std;

int S;

struct P{
    int peo;
    int time;
};

class G{
public:
    int num;
    list<P> *adj;
    vector<int> ans;

    G(int a){
        this->num = a;
        adj = new list<P>[num];
    }

    void add(int u, P& v){
        adj[u].push_back(v);
    }

    void solve(){
        queue<P> bfs;
        P init = {S, 0};
        bfs.push(init);

        while(!bfs.empty()){
            P temp = bfs.front();
            //cout << "temp= " << temp.peo << endl;
            bfs.pop();

            if(adj[temp.peo].empty()){
                ans.push_back(temp.time);
                continue;
            }

            list<P>::iterator j;
            for(j = adj[temp.peo].begin();j != adj[temp.peo].end();j++){
                P next = {(*j).peo, temp.time + (*j).time};
                bfs.push(next);
            }
        }
    }
};

int main () {
    int t, n;
    cin >> t;
    while(t--){
        cin >> n >> S;
        G g(n);
        int from, time;
        for(int i = 0;i < n;i++){
            cin >> from >> time;
            if(i == S)
                continue;
            P temp = {i, time};
            g.add(from, temp);
        }
        g.solve();
        sort(g.ans.begin(), g.ans.end());
        cout << g.ans[g.ans.size()-1] << endl;
    }
}