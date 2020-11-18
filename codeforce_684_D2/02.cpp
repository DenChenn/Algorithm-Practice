#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    int m, n, k;
    cin >> t;
    while(t--){
        long long sum = 0;
        long long temp;
        cin >> n >> k;
        for(int i = 0;i < n*k;i++){
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        m = n / 2 + 1;
        
        int index = n*k - m;
        for(int i = 0;i < k;i++){
            sum += arr[index];
            index -= m;
        }
        cout << sum << endl;
        arr.clear();
    }
}