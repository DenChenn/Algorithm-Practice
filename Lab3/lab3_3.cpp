#include <bits/stdc++.h>
using namespace std;

int R = 0;
bool hp[10001];

class Graph{
public:
    int num;
    list<int> *adj;
    bool *need;
    vector<int> path;

    Graph(int num){
        this->num = num;
        this->adj = new list<int>[num]; 
        this->need = new bool[num];
        fill_n(need, this->num, false);
    }

    void add(int v, int w){
        adj[v].push_back(w);
    }

    bool check(vector<int>& a, int tar){
        bool f = false;
        for(auto b : a){
            if(b == tar){
                f = true;
                break;
            }
        }
        return f;
    }

//bfs
    bool solve(int eq){
        queue<int> bfs;
        bfs.push(eq);
        path.push_back(eq);

        while(!bfs.empty()){
            int temp = bfs.front();
            bfs.pop();
            //cout << "temp= " << temp << endl;

            if(path.size() > R*R)
                return false;
            

            if(adj[temp].empty()){
                //cout << "inin" << endl;
                path.push_back(temp);
                continue;
            }

            list<int>::iterator j;
            for(j = adj[temp].begin();j != adj[temp].end();j++){
                //cout << "j= " << *j << endl;
                bfs.push(*j);
                path.push_back(*j);  
            }
        }
        return true;
    }
};

int main () {
    int t, K, N;
    int room, key;
    cin >> t;
    while(t--){
        cin >> R >> K >> N;
        Graph g(R);
        fill_n(hp, 10001, false);
        for(int i = 0;i < K;i++){
            cin >> room >> key;
            g.add(key, room);
        }
        if(g.solve(N)){
            vector<int>::iterator i;
            //輸出處理
            for(i = g.path.end()-1;i >= g.path.begin();i--){
                if(!hp[*i] && *i != N){
                    cout << *i << " ";
                    hp[*i] = true;
                }
            }
            cout << N << endl;
        }
        else
            cout << "Lion can not pass this chapter!" << endl;
        
    }
    return 0;
}