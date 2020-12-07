#include <bits/stdc++.h>
using namespace std;
long long cnt;

int solve(long long n){
    if(n == 1)
        return cnt;

    if(n % 2 == 1){
        cnt++;
        return solve(n-1);
    }
    else if(n == 2){
        cnt++;
        return solve(1);
    }
    else{
        cnt++;
        return solve(2);
    }
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cnt = 0;
        cout << solve(n) << endl;
    }
    return 0;
}