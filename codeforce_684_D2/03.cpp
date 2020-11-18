#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int m[100001];
int r, c;
vector<int> ans;
int cnt;

bool check(){
    for(int i = 0;i < 100001;i++){
        if(m[i] == 1)
            return false;
    }
    return true;
}

void solve(int st){
    if(check())
        return;
    if(st / r == r - 1){
        ans.clear();
        cnt = 0;
        return;
    }
    else if (st % c == c - 1){
        solve(st + 1);
        return;
    }
    
    
    
    m[st] = !m[st];
    m[st+c] = !m[st+c];
    m[st+c+1] = !m[st+c+1];
    ans.push_back(st);
    ans.push_back(st+c);
    ans.push_back(st+c+1);
    cnt++;
    solve(st + 1);
    m[st] = !m[st];
    m[st+c] = !m[st+c];
    m[st+c+1] = !m[st+c+1];

    m[st+1] = !m[st+1];
    m[st+c] = !m[st+c];
    m[st+c+1] = !m[st+c+1];
    ans.push_back(st+1);
    ans.push_back(st+c);
    ans.push_back(st+c+1);
    cnt++;
    solve(st + 1);
    m[st+1] = !m[st+1];
    m[st+c] = !m[st+c];
    m[st+c+1] = !m[st+c+1];


    m[st] = !m[st];
    m[st+1] = !m[st+1];
    m[st+c] = !m[st+c];
    ans.push_back(st);
    ans.push_back(st+1);
    ans.push_back(st+c);
    cnt++;
    solve(st + 1);
    m[st] = !m[st];
    m[st+1] = !m[st+1];
    m[st+c] = !m[st+c];


    m[st] = !m[st];
    m[st+1] = !m[st+1];
    m[st+c+1] = !m[st+c+1];
    ans.push_back(st);
    ans.push_back(st+1);
    ans.push_back(st+c+1);
    cnt++;
    solve(st + 1);
    m[st] = !m[st];
    m[st+1] = !m[st+1];
    m[st+c+1] = !m[st+c+1];
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    string temp;
    cin >> t;
    while(t--){
        cin >> r >> c;
        int idx = 0;
        for(int i = 0;i < r;i++){
            cin >> temp;
            for(int j = 0;j < c;j++){
                m[idx] = temp[j];
                idx++;
            }
        }
        solve(0);
        cout << cnt << endl;
        for(auto a : ans)
            cout << a / r << " " << a % c << " ";
        cout << endl;
    }
    return 0;
}