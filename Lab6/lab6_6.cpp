#include<bits/stdc++.h>
using namespace std;;

int Rg[110][110];
int parent[110];
int start = 0, termi = 104;
int N;

bool bfs(){
	queue<int> q;
	bool visited[110];
	for(int i = 0; i < 110; i++){
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
	int T, M, P, A;
	int u, v, c;
	int temp;
	cin >> T;
	while(T--){
		cin >> N >> M >> P >> A;
		init();
		for(int i = 0;i < P;i++){
			cin >> temp;
			Rg[start][temp] = INT_MAX;
		}
		for(int i = 0;i < A;i++){
			cin >> temp;
			Rg[temp][termi] = INT_MAX;
		}
		for(int i = 0;i < M;i++){
			cin >> u >> v >> c;
			Rg[u][v] = c;
		}
		cout << ford_fulkerson() << endl;
	} 
	
	return 0;
} 
