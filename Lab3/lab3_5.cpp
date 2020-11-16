#include <bits/stdc++.h>
using namespace std;
#define N 10001

vector<int> edge[N];
int dfn[N];
int low[N];
int component[N]; //將點縮成一個ＳＣＣ id, 可以視為是一個新的圖
int indegree[N];
bool instack[N];
stack<int> st;
int T, C;

void init(int num){
    for(int i = 1;i <= num;i++){
        instack[i] = false;
        edge[i].clear();
        dfn[i] = 0;
    }

    while(st.size())
        st.pop();

    T = 0;
    C = 0;
}

void tarjan(int u){
    dfn[u] = low[u] = ++T;
    st.push(u);
    instack[u] = true;

    for(int i = 0;i < edge[u].size();i++){
        int v = edge[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u], dfn[v]);
    }

    if(dfn[u] == low[u]){
        int ele;
        C++;
        indegree[C] = 0; //初始化一組強聯通元件的入度為0

        do{
            ele = st.top();
            st.pop();
            instack[ele] = false;
            component[ele] = C;
        }while(ele!= u);
    }
}

int main () {
    int t, num, rel;
    int from, dst;
    cin >> t;
    while(t--){
        cin >> num >> rel;
        init(num);
        for(int i = 0;i < rel;i++){
            cin >> from >> dst;
            edge[from].push_back(dst);
        }

        for(int u = 1;u <= num;u++){
            if(!dfn[u])
                tarjan(u);
        }

        //計算新的DAG的各個點的入度
        for(int u = 1;u <= num;u++){
            for(int i = 0;i < edge[u].size();i++){
                int v = edge[u][i];
                if(component[u] != component[v])
                    indegree[component[v]]++;
            }
        }


        int ans = 0;
        for(int c = 1;c <= C;c++){
            if(indegree[c] == 0)
                ans++;
        }
        cout << ans << endl;
    }
}