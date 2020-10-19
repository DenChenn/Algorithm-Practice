#include<iostream>
#include<cstring>
using namespace std;

struct P {
	P(int a, int b, int c, int d): x(a), y(b), px(c), py(d){}
	int x;
	int y;
	int px;
	int py;
};

int m[65][65];

void clone(bool a[][65], bool b[][65], int row, int col){
	for(int i = 0;i < row;i++){
		for(int j = 0;j < col;j++)
			a[j][i] = b[j][i];
	}
}

void solve(int m[][65], P pos, int& ans, int row, int col, bool rem[][65]){
	if(pos.x == col - 1 && pos.y == row - 1){
		ans++;
		return;
	}

	if(pos.x - pos.px == 1){
		if(!rem[pos.x+1][pos.y] && m[pos.x][pos.y] == 'L' && pos.x+1 < col && m[pos.x+1][pos.y] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x+1][pos.y] = true;
			solve(m, P(pos.x+1, pos.y, pos.x, pos.y), ans, row, col, con);
		}
		
		if(!rem[pos.x][pos.y+1] && m[pos.x][pos.y] == 'T' && pos.y + 1 < row && m[pos.x][pos.y+1] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x][pos.y+1] = true;
			solve(m, P(pos.x, pos.y+1, pos.x, pos.y), ans, row, col, con);
		}

		if(!rem[pos.x][pos.y-1] && m[pos.x][pos.y] == 'T' && pos.y - 1 >= 0 && m[pos.x][pos.y+1] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x][pos.y-1] = true;
			solve(m, P(pos.x, pos.y-1, pos.x, pos.y), ans, row, col, con);
		}
	}

	if(pos.x - pos.px == -1){
		if(!rem[pos.x-1][pos.y] && m[pos.x][pos.y] == 'L' && pos.x-1 >=0 && m[pos.x-1][pos.y] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x-1][pos.y] = true;
			solve(m, P(pos.x-1, pos.y, pos.x, pos.y), ans, row, col, con);
		}
		if(!rem[pos.x][pos.y+1] && m[pos.x][pos.y] == 'T' && pos.y + 1 < row && m[pos.x][pos.y+1] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x][pos.y+1] = true;
			solve(m, P(pos.x, pos.y+1, pos.x, pos.y), ans, row, col, con);
		}

		if(!rem[pos.x][pos.y-1] && m[pos.x][pos.y] == 'T' && pos.y - 1 >= 0 && m[pos.x][pos.y+1] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x][pos.y-1] = true;
			solve(m, P(pos.x, pos.y-1, pos.x, pos.y), ans, row, col, con);
		}
	}

	if(pos.y - pos.py == 1){
		if(!rem[pos.x][pos.y+1] && m[pos.x][pos.y] == 'L' && pos.y+1 < row && m[pos.x][pos.y+1] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x][pos.y+1] = true;
			solve(m, P(pos.x, pos.y+1, pos.x, pos.y), ans, row, col, con);
		}
		if(!rem[pos.x+1][pos.y] && m[pos.x][pos.y] == 'T' && pos.x + 1 < col && m[pos.x+1][pos.y] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x+1][pos.y] = true;
			solve(m, P(pos.x+1, pos.y, pos.x, pos.y), ans, row, col, con);
		}

		if(!rem[pos.x-1][pos.y] && m[pos.x][pos.y] == 'T' && pos.x - 1 >= 0 && m[pos.x-1][pos.y] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x-1][pos.y] = true;
			solve(m, P(pos.x-1, pos.y, pos.x, pos.y), ans, row, col, con);
		}
	}

	if(pos.y - pos.py == -1){
		if(!rem[pos.x][pos.y-1] && m[pos.x][pos.y] == 'L' && pos.y-1 >= 0 && m[pos.x][pos.y-1] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x][pos.y-1] = true;
			solve(m, P(pos.x, pos.y-1, pos.x, pos.y), ans, row, col, con);
		}
		
		if(!rem[pos.x+1][pos.y] && m[pos.x][pos.y] == 'T' && pos.x + 1 < col && m[pos.x+1][pos.y] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x+1][pos.y] = true;
			solve(m, P(pos.x+1, pos.y, pos.x, pos.y), ans, row, col, con);
		}

		if(!rem[pos.x-1][pos.y] && m[pos.x][pos.y] == 'T' && pos.x - 1 >= 0 && m[pos.x-1][pos.y] != 'B'){
			bool con[65][65];
			clone(con, rem, row, col);
			con[pos.x-1][pos.y] = true;
			solve(m, P(pos.x-1, pos.y, pos.x, pos.y), ans, row, col, con);
		}
	}
	return;
}

int main () {
	int t;
	int row, col;
	char temp;
	cin >> t;
	while(t--){
		cin >> row >> col;
		int ans = 0;
		bool rec[65][65];
		memset(rec, false, sizeof(rec));
		rec[0][0] = true;
		for(int i = 0;i < row;i++){
			for(int j = 0;j < col;j++){
				cin >> temp;
				m[j][i] = temp;
			}
		}
		P pos = {0, 0, -1, -1};
	

		solve(m, pos, ans, row, col, rec);
		cout << "Number of legal solutions: " << ans << endl;
	}
	return 0;
}

