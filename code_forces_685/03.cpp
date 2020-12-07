#include <bits/stdc++.h>
using namespace std;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    vector<int> a;
    vector<int> b;
    string t1, t2;
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> t1;
        cin >> t2;
        for(int i = 0;i < n;i++){
            a.push_back(t1[i] - 97);
            b.push_back(t2[i] - 97);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end()); 
        int index = 0;
        int ye = 0;
        while(index < n){
            if(a[index] == b[index]){
                index++;
                continue;s
            }
            int f1 = 0, f2 = 0;
            for(int i = index;i < index + k - 1;i++){
                if(a[i] != a[i + 1]){
                    f1 = 1;
                    break;
                }
            }
            if(f1){
                ye = 1;
                break;
            }
            for(int i = index;i < index + k - 1;i++){
                if(b[i] != b[i + 1]){
                    f2 = 1;
                    break;
                }
            }
            if(f2){
                ye = 1;
                break;
            }
            if(a[index] > b[index]){
                ye = 1;
                break;
            }
            index += k;
        }
        if(ye)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
        a.clear();
        b.clear();
    }
}