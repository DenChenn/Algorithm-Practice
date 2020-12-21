#include <bits/stdc++.h>
using namespace std;

vector<char> KKK;
vector<char> OOO;
int len;
char ans[500010];

void init(){
    KKK.clear();
    OOO.clear();
    len = 0;
}

bool CmpS(char& a, char& b){
    return (a < b);
}

bool CmpL(char& a, char& b){
    return (a > b);
}

void solve() {
    int k_first = 0, k_end, o_first = 0, o_end;
    int half_k, half_o;
    int ans_first = 0, ans_end = len - 1;
    bool spec1 = false, spec2 = false;

    if(len % 2 == 1){
        half_k = len / 2 + 1;
        half_o = len / 2;
    }
    else{
        half_k = len / 2;
        half_o = len / 2;
    }
    k_end = half_k - 1;
    o_end = half_o - 1;

    for(int i = 0;i < len;i++){
        if(OOO[o_first] <= KKK[k_first]){
            spec1 = true;
        }
        if(KKK[k_first] >= OOO[o_first]){
            spec2 = true;
        }
        if(i % 2 == 0){ // K turn
            if(spec1){
                ans[ans_end] = KKK[k_end];
                k_end--;
                ans_end--;
            }
            else{
                ans[ans_first] = KKK[k_first];
                k_first++;
                ans_first++;
            }
        }
        else{ // O turn
            if(spec2){
                ans[ans_end] = OOO[o_end];
                o_end--;
                ans_end--;
            }
            else{
                ans[ans_first] = OOO[o_first];
                o_first++;
                ans_first++;
            }
        }
    }

}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t1, t2;
    int time;
    cin >> time;

    while(time--){
        init();
        cin >> t1 >> t2;
        len = t1.length();
        for(int i = 0;i < len;i++){
            KKK.push_back(t1[i]);
            OOO.push_back(t2[i]);
        }
        sort(KKK.begin(), KKK.end(), CmpS);
        sort(OOO.begin(), OOO.end(), CmpL);
        solve();
        for(int i = 0;i < len;i++){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}