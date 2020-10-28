#include<bits/stdc++.h>
using namespace std;

int row, col, ans;
char m[65][65];
bool visited[65][65];

void solve(int x, int y, bool is_hori){
	//cout << x << " " << y << endl;
	if(x == col-1 && y == row-1){ 
		if(m[x][y] == 'B')
			return;
		//cout << "yaya" << endl;
		ans++;
		return;
	}
	

	if(x < 0 || x >= col || y < 0 || y >= row || visited[x][y])
		return;
	
	visited[x][y] = true;
		
	if(m[x][y] == 'B')
		return;	
	else if(m[x][y] == 'L'){ 
		if(is_hori){
			//cout << "1" << endl;
			solve(x+1, y, true);
			solve(x-1, y, true);
		}
		else{
			//cout << "2" << endl;
			solve(x, y+1, false);
			solve(x, y-1, false);
		}
	}
	else if(m[x][y] == 'T'){
		if(is_hori){
			//cout << "3" << endl;
			solve(x, y+1, false);
			solve(x, y-1, false);
		}
		else{
			//cout << "4" << endl;
			solve(x+1, y, true);
			solve(x-1, y, true);
		}
	}
	 
	visited[x][y] = false;
	return;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> row >> col;
		
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				cin >> m[j][i];	
		
		ans = 0;
		bool is_hori = true;

		memset(visited, false, sizeof(visited));
		solve(0, 0, is_hori);
		
		memset(visited, false, sizeof(visited));
		solve(0, 0, !is_hori);
		
		cout << "Number of legal solutions: " << ans << endl;
	}
	
	return 0;
}
