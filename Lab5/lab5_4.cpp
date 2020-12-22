#include <bits/stdc++.h>
using namespace std;
int ans;
int num;
int used[10010]; // 0代表用x 1代表用y
int x_used, y_used;

struct R{
    int x;
    int y;
};

struct S{
    int id;
    int differ;
};

vector<R> record;
vector<S> swapp;

void init() {
    ans = 0;
    for(int i = 0;i < num;i++)
        used[i] = 0;
    record.clear();
    swapp.clear();
    x_used = 0;
    y_used = 0;
}

bool Cmp(S& s1, S& s2){
    return s1.differ < s2.differ;
}

void solve() {
    for(int i = 0;i < num;i++){
        if(record[i].x > record[i].y){
            used[i] = 1;
            ans += record[i].y;
            y_used++;
        }
        else {
            used[i] = 0;
            ans += record[i].x;
            x_used++;
        } 
    }

    if(x_used > y_used){
        for(int i = 0;i < num;i++){
            if(used[i] == 0){
                int difference = record[i].y - record[i].x;
                S s;
                s.id = i; s.differ = difference;
                swapp.push_back(s);
            }
        }
        sort(swapp.begin(), swapp.end(), Cmp);
        for(int i = 0;i < (x_used - y_used) / 2;i++){
            ans = ans + record[swapp[i].id].y - record[swapp[i].id].x;
        }
    }
    else if(y_used > x_used){
        for(int i = 0;i < num;i++){
            if(used[i] == 1){
                int difference = record[i].x - record[i].y;
                S s;
                s.id = i; s.differ = difference;
                swapp.push_back(s);
            }
        }
        sort(swapp.begin(), swapp.end(), Cmp);
        for(int i = 0;i < (y_used - x_used) / 2;i++){
            ans = ans + record[swapp[i].id].x - record[swapp[i].id].y;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, index;
    int x, y;
    cin >> t;
    while(t--){
        index = 0;
        init();
        cin >> num;
        
        for(int i = 0;i < num;i++){
            cin >> x >> y;
            R r;
            r.x = x; r.y = y;
            record.push_back(r);
            index++;
        }
        solve();
        cout << ans << endl;
    }
    return 0;
}