#include <bits/stdc++.h>
using namespace std;
using Time = pair<int, int>;

vector<Time> ef;
int cnt;

void init() {
    ef.clear();
    cnt = 0;
}

void solve() {
    int now = ef[0].first;
    cnt++;
    for(auto a : ef){
        if(a.second >= now){
            cnt++;
            now = a.first;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, start, end, ans;
    cin >> t;
    while(t--){
        init();
        cin >> n;
        for(int i = 0;i < n;i++){
            Time t;
            cin >> t.second >> t.first;
            ef.push_back(t);
        }
        sort(ef.begin(), ef.end());
        solve();
        cout << cnt << endl;
    }
    return 0;
}
