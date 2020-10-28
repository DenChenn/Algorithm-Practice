#include <bits/stdc++.h>
using namespace std;

int card[10001];
bool r[10001];
bool l[10001];

bool solve(int start, int N){
    if (card[start] == 0)
        return true;

    if (start + card[start] < N && !r[start]){
        r[start] = true;
        if(solve(start + card[start], N))
            return true;
    }

    if (start - card[start] >= 0 && !l[start]){
        l[start] = true;
        if(solve(start - card[start], N))
            return true;
    }

    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, N, s;
    cin >> t;
    while(t--){
        fill_n(r, 10001, false);
        fill_n(l, 10001, false);
        cin >> N >> s;
        for(int i = 0;i < N;i++)
            cin >> card[i];
        if (solve(s, N))
            cout << "We will watch your career with great interest." << endl;
        else 
            cout << "My disappointment is immeasurable, and my day is ruined." << endl;
    }
    return 0;
}