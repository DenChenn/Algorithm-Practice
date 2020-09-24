#include <iostream>
using namespace std;
int arr[1001][1001];

struct Pos{
    Pos();
    Pos(int a, int b){
        r = a;
        c = b;
    }
    int r;
    int c;
};

Pos ser_2d(int arr[][1001], int tar, Pos p, int limit_row){
    if(arr[p.r][p.c] == tar)
        return Pos(p.r,p.c);

    if(tar > arr[p.r][p.c] && p.r + 1 < limit_row)
        return ser_2d(arr, tar, Pos(p.r+1,p.c), limit_row);
    else if (tar < arr[p.r][p.c] && p.c - 1 >= 0)
        return ser_2d(arr, tar, Pos(p.r,p.c-1), limit_row);

    return Pos(-1,-1);
}

int main() {
    int row, col, t, temp;
    cin >> row >> col >> t;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    int tar;
    while(t--){
        cin >> tar;
        Pos init = {0,col-1};
        Pos ans = ser_2d(arr, tar, init, row);
        
        if(ans.r == -1)
            cout << -1 << endl;
        else 
            cout << ans.r << " " << ans.c << endl;
    }
}

