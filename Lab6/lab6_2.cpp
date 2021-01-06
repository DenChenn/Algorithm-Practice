#include<bits/stdc++.h>
using namespace std;
int L;
int LIS[1001];
int LDS[1001];

vector<int> M;

int LBS(){
    fill_n(LIS, L, 1);
    fill_n(LDS, L, 1);
    vector<int> vec;
    //利用bottom-up的方式由左而右計算每一個end的LIS
    for(int i = 0;i < L;i++){
        if(vec.empty() || vec.back() < M[i]){
            vec.push_back(M[i]);
        }
        else{
            int p;
            p = lower_bound(vec.begin(), vec.end(), M[i]) - vec.begin();
            vec[p] = M[i];
        }
        LIS[i] = vec.size();
    }
    vec.clear();

    //利用bottom-up的方式由右而左計算每一個end的LDS
    for(int i = L-1;i >= 0;i--){
        if(vec.empty() || vec.back() < M[i]){
            vec.push_back(M[i]);
        }
        else{
            int p;
            p = lower_bound(vec.begin(), vec.end(), M[i]) - vec.begin();
            vec[p] = M[i];
        }
        LDS[i] = vec.size();
    }

    int max = -1;
    for(int i = 0;i < L;i++){
        if(LIS[i] == 1 || LDS[i] == 1) //特殊判斷情況
            continue;
        if(LIS[i] + LDS[i] - 1 > max)
            max = LIS[i] + LDS[i] - 1;
    }
    return max;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        M.clear();
        cin >> L;
        int temp;
        for(int i = 0;i < L;i++){
            cin >> temp;
            M.push_back(temp);
        }
        cout << L - LBS() << endl;
    }
    return 0;
}