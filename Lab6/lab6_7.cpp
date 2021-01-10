#include<bits/stdc++.h>
using namespace std;;

int Rg[220][220];
int parent[220];
int start = 0, termi = 205;
int N;

bool bfs(){
	queue<int> q;
	bool visited[220];
	for(int i = 0; i < 220; i++){
		visited[i] = false;
		parent[i] = -1;
	}
	
	q.push(start);
	visited[start] = true;
	
	while(!q.empty()){
		int u = q.front();	
		visited[u] = true;	
		q.pop();
		
		for(int v = 0;v < termi+1;v++){
            if(!visited[v] && Rg[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
	}
	
	return visited[termi] == true;
}

int ford_fulkerson(){
	int ans = 0;

	while(bfs()){
		int minflow = INT_MAX;
		for(int i = termi; i != start; i = parent[i]){
			int j = parent[i];
			minflow = min(minflow, Rg[j][i]);
		}
		ans += minflow;
		for(int i = termi; i != start; i = parent[i]){
			int j = parent[i];
			
			Rg[j][i] -= minflow;
			Rg[i][j] += minflow;			
		}
	}
	return ans;
}

void init(){	
	memset(Rg, 0, sizeof(Rg));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int T, N, M, K;
    int from, to;
	cin >> T;
	while(T--){
        init();
		cin >> N >> M >> K;
        for(int i = 0;i < N;i++){
            Rg[start][i+1] = 1; // N = 1 ~ 101
        }
        for(int i = 0;i < M;i++){
            Rg[i+102][termi] = 1; // M = 102 ~ 200
        }
        for(int i = 0;i < K;i++){
            cin >> from >> to;
            Rg[from+1][to+102] = 1; //space 0 for super src
        }
        cout << ford_fulkerson() << endl;
	} 
	return 0;
} 
