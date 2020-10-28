#include <bits/stdc++.h>
using namespace std;

int R;

class Graph{
public:
    int num;
    list<int> *adj;
    bool *need;
    Graph(int num){
        num = num;
        adj = new list<int>[num];
        need = new bool[num];
        fill_n(this->need, num, false);

    }
    void add(int v, int w){
        adj[v].push_back(w);
    }

    bool solve(int eq){
        for(int i = 0;i < num;i++){
            
            if(!need[i]){
                dfs(i, eq);
            }
        }
    }

    bool dfs(int i, int eq){
        list<int>::iterator j; 
        for(j = adj[i].begin();j != adj[i].end();++j){
            if(*j == eq){
                return true;
            }
            
            if(adj[*j].size() == 0)
                return false;

            if(dfs(*j, eq)){
                cout << *j << " ";
            }
        }
    }
}

int main () {
    int t, K, N;
    int room, key;
    cin >> t;
    while(t--){
        cin >> R >> K >> N;
        Graph g(R);
        for(int i = 0;i < K;i++){
            cin >> room >> key;
            g.add(room, key);
            g.need[key] = true;
        }
        g.solve(N);
    }
    return 0;
}