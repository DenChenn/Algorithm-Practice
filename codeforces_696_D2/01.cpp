#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    vector<int> a;
    vector<int> b;
    cin >> t;
    getchar();
    while(t--){
        int n, pre, temp, next;
        a.clear();
        b.clear();
        cin >> n;
        getchar();
        for(int i = 0;i < n;i++){
            temp = getchar();
            b.push_back(temp-48);
        }
        getchar();
        pre = -1;
        for(auto x : b){
            if (x + 1 != pre){
                pre = x + 1;
                a.push_back(1);
            }
            else{
                pre = x;
                a.push_back(0);
            }
        }
        for(auto x : a){
            cout << x;
        }
        cout << endl;
    }
    return 0;
}