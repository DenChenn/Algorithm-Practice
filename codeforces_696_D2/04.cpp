#include <bits/stdc++.h>
using namespace std;
vector<int> sw;

bool solve(vector<int> ppcp, int i, int n){
    bool ans = true;
    int t = ppcp[i];
    ppcp[i] = ppcp[i+1];
    ppcp[i+1] = t;

    for(int j = 0;j < n-1;j++){
        int de = min(ppcp[j], ppcp[j+1]);
        ppcp[j] -= de;
        ppcp[j+1] -= de;
    }
    for(int j = 0;j < n;j++){
        if(ppcp[j] != 0){
            ans = false;
            break;
        }
    }
    if(ans)
        return ans;
    t = ppcp[i];
    ppcp[i] = ppcp[i+1];
    ppcp[i+1] = t;
    if(i > 0){
        t = ppcp[i];
        ppcp[i] = ppcp[i-1];
        ppcp[i-1] = t;
        for(int j = 0;j < n-1;j++){
            int de = min(ppcp[j], ppcp[j+1]);
            ppcp[j] -= de;
            ppcp[j+1] -= de;
        }
        for(int j = 0;j < n;j++){
            if(ppcp[j] != 0){
                ans = false;
                break;
            }
        }
        return ans;
    }
    return false;
}
bool nosw(vector<int> ppcp, int n){
    for(int j = 0;j < n-1;j++){
        int de = min(ppcp[j], ppcp[j+1]);
        ppcp[j] -= de;
        ppcp[j+1] -= de;
    }
    bool ans = true;
    for(int j = 0;j < n;j++){
        if(ppcp[j] != 0){
            sw.push_back(j);
            ans = false;
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    int n;
    vector<int> pp;
    while(t--){
        sw.clear();
        pp.clear();
        int temp;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> temp;
            pp.push_back(temp);
        }
        bool can = false;
        if(nosw(pp, n)){
            cout << "YES" << endl;
            continue;
        }
        for(auto x : sw){
            cout << "x: " << x << endl;
        }
        for(auto i : sw){
            if(solve(pp, i, n)){
                can = true;
                break;
            }
        }
        if(can)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}