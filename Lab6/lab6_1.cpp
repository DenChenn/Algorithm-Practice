#include <bits/stdc++.h>
using namespace std;
int dp[500][500]; // 儲存每個小問題的答案，初始化為-1
bool visited[500];
string s1;
vector<char> s;
int L;
int ans;
int accu;
char pre;
vector<char> unused;

void init() {

    fill_n(visited, L, false);
    for(int i = 0;i < L;i++){
        visited[i] = false;
        for(int j = 0;j < L;j++){
            dp[i][j] = -1;
        }
    }
}

int LengthOfLPS(int i, int j){
    //cout << "i: " << s[i] << " j: " << s[j] << endl;
    if (i == j) return 1;
    if (i > j) return 0;
    if (dp[i][j] != -1) {
        //cout << "-----11111" << " " << dp[i][j] << endl;
        return dp[i][j];
    }
 
    // 左右兩端字元相等，定能形成更長迴文，同時從兩端縮小問題範疇。
    if (s[i] == s[j]){
        cout << "inin1" << endl;
        dp[i][j] = LengthOfLPS(i+1, j-1) + 2;
        if(s[i] != pre){
            ans++;
            pre = s[i];
        }
        visited[i] = true; visited[j] = true;
    }

    // 刪除左端字元比較好 || 都一樣好
    else if (LengthOfLPS(i+1, j) >= LengthOfLPS(i, j-1)){
        //cout << "inin2" << endl;
        dp[i][j] = LengthOfLPS(i+1, j);
        pre = '0';
    }

    // 刪除右端字元比較好。
    else {
        //cout << "inin3" << endl;
        dp[i][j] = LengthOfLPS(i, j-1);
        pre = '0';
    }

    return dp[i][j];
}

void solve() {
    int l;
    //while(s.size() != 1){
        for(auto a : s)
            cout << a << " ";
        cout << endl;
        init();
        pre = '0';
        l = LengthOfLPS(0, L-1);
        accu += l;
        for(int i = 0;i < L;i++){
            if(!visited[i])
                unused.push_back(s[i]);
        }
        s.clear();
        for(int i = 0;i < unused.size();i++)
            s.push_back(unused[i]);
        unused.clear();

        for(auto a : s)
            cout << a << " ";
        cout << endl;
        init();
        pre = '0';
        l = LengthOfLPS(0, L-1);
        accu += l;
        for(int i = 0;i < L;i++){
            if(!visited[i])
                unused.push_back(s[i]);
        }
        s.clear();
        for(int i = 0;i < unused.size();i++)
            s.push_back(unused[i]);
        unused.clear();

        for(auto a : s)
            cout << a << " ";
        cout << endl;
        init();
        pre = '0';
        l = LengthOfLPS(0, L-1);
        accu += l;
        for(int i = 0;i < L;i++){
            if(!visited[i])
                unused.push_back(s[i]);
        }
        s.clear();
        for(int i = 0;i < unused.size();i++)
            s.push_back(unused[i]);
        unused.clear();
    //}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;  
    while(t--){
        cin >> L;
        s.clear();
        cin >> s1;
        for(int i = 0;i < L;i++)
            s.push_back(s1[i]);
        init();
        ans = 0; accu = 0; pre = '0';     
        solve();
        cout << ans << endl;
    }
    return 0;
}