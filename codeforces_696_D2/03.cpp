#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, n, temp;
    vector<int> arr;
    cin >> t;
    while(t--){
        arr.clear();
        cin >> n;
        for(int i = 0;i < 2*n;i++){
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        bool can = true;
        int s = arr[0] + arr[2*n-1];
        cout << arr[0] << " " << arr[2*n-1] << endl;
        for(int i = 1;i < n;i++){
            
            if(arr[i] + arr[2*n-1-i] != s){
                cout << arr[i] << " " << arr[2*n-1-i] << endl;
                can = false;
                break;
            }
        }
        if(!can){
            cout << "NO" << endl;
            continue;
        }
        else{
            cout << "YES" << endl;
            for(int i = 0;i < n;i++){
                cout << arr[i] << " " << arr[2*n-1-i] << endl;
            }
            continue;
        }
    }
    return 0;
}