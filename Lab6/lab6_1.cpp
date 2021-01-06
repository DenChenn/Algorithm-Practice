#include <bits/stdc++.h>
using namespace std;
int dp[600][600]; // 儲存每個小問題的答案，初始化為-1
string s;
int L;


int MinimumDeletion(int l, int r) {
    if (l > r) 
        return 0; 
    if (l == r) 
        return 1; 
    if (dp[l][r] != -1) 
        return dp[l][r]; 
  
    //從第一個開始考慮 如果那個是自己獨立刪掉的狀況
    int res = 1 + MinimumDeletion(l + 1, r); 
  
    //或是跟其他一樣的一起刪掉 
    for (int i = l + 1; i <= r; ++i) { 
  
        //找到一樣的並且刪掉中間的
        if (s[l] == s[i]) 
            //後面的部份有考慮到i 所以不用像上面一樣+1
            res = min(res, MinimumDeletion(l + 1, i - 1) + MinimumDeletion(i, r)); 
    } 
  
    // Memoize 
    return dp[l][r] = res; 
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;  
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> L;
        cin >> s;
        cout << MinimumDeletion(0, L-1) << endl;
    }
    return 0;
}