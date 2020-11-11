#include <bits/stdc++.h>
using namespace std;

bool nop[10001];
int DFN[10001];
int low[10001];
int dindex = 0;
int instack[10001];
stack<int> st;
int SCC[10001];

class Graph{
public:
    int num;
    list<int>* adj;
    Graph(int n){
        num = n;
        adj = new list<int>[n+1];
        for(int i = 0;i < n;i++)
            adj[i].clear();
    }

    void add(int u, int v){
        adj[u].push_back(v);
    }
};

void tarjan(int i, Graph& g){
    DFN[i] = ++dindex;
    low[i] = ++dindex;
    instack[i] = true;
    st.push(i);

    list<int>::iterator k;
    if(!g.adj[i].empty()){
    for(k = g.adj[i].begin();k != g.adj[i].end();k++){
        if(!DFN[*k]){
            tarjan(*k, g);
            low[i] = min(low[i], low[*k]);
        }
        else if(instack[*k])
            low[i] = min(low[i], DFN[*k]);           
    }
    }
    if(DFN[i] == low[i]){
        int now;
        while(true){
            now = st.top();
            st.pop();
            if(now == i)
                break;
            //cout << now << " ";
        }
        //cout << endl;
    }
}

int solve(int num, Graph& g){
    fill_n(DFN, 10001, 0);
    fill_n(instack, 10001, false);
    bool allcon = true;
    int ans = 0;

    for(int i = 1;i < num;i++){
        if(nop[i] && !DFN[i]){
            allcon = false;
            tarjan(i, g);
            ans++;
        }
    }

    
    for(int i = 1;i < num;i++){
        if(!DFN[i]){
            allcon = false;
            tarjan(i, g);
            ans++;
        }
    }
    
    return ans;
}

int main () {
    int t, num, rel;
    cin >> t;
    while(t--){
        cin >> num >> rel;
        fill_n(nop, 10001, true);
        int from, dst;
        Graph g(num);
        for(int i = 0;i < rel;i++){
            cin >> from >> dst;
            g.add(from, dst);
            nop[dst] = false;
        }

        cout << solve(num, g) << endl;        
    }
    return 0;
}