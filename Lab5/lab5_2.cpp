#include <bits/stdc++.h>
using namespace std;
#define score first
#define dead second
using Ass = pair<int,int>;

vector<Ass> HW;
long long cnt;
priority_queue<int, vector<int>, less<int>> pq;

bool Cmp(Ass& a, Ass& b){
    return (a.dead > b.dead);
}

void init() {
    HW.clear();
    while(!pq.empty())
        pq.pop();
    cnt = 0;
}

void solve(){
    int i = 0, j;

    while(i < HW.size()){
        start = HW[i].dead;
        for(j = i;j < HW.size();j++){
            if(HW[j].dead != HW[i].dead){
                end = HW[j].dead;
                i = j;
                break;
            }
            pq.push(HW[j].score);
        }
        if(i == j){
            for(int k = 0;k < start - end;k++){
                if(pq.empty())
                    break;
                cnt += pq.top();
                pq.pop();
            }
        }
        else{
            for(int k = 0;k < HW[i].dead;k++){
                if(pq.empty())
                    break;
                cnt += pq.top();
                pq.pop();
            }
            break;
        }
    }
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        init();
        cin >> n;
        for(int i = 0;i < n;i++){
            Ass a;
            cin >> a.dead >> a.score;
            HW.push_back(a);
        }
        sort(HW.begin(), HW.end(), Cmp);
        
        solve();
        cout << cnt << endl;
    }
    return 0;
}