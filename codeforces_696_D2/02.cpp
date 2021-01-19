#include <bits/stdc++.h>
using namespace std;

bool prime[20000000];
void eratosthenes() {
    for (int i=0; i<20000000; i++)  // 初始化
        prime[i] = true;
 
    prime[0] = false;   // 0 和 1 不是質數
    prime[1] = false;
 
    // 找下一個未被刪掉的數字
    for (int i=2; i<20000000; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for (int j=i+i; j<20000000; j+=i)
                prime[j] = false;
}

int main () {
    eratosthenes();
    vector<int> pp;
    for(int i = 1;i < 20000000;i++){
        if(prime[i])
            pp.push_back(i);
    }
    int t, d, f_index, s_index;
    cin >> t;
    while(t--){
        cin >> d;
        f_index =lower_bound(pp.begin(), pp.end(), 1+d) - pp.begin();
        s_index = lower_bound(pp.begin(), pp.end(), pp[f_index]+d) - pp.begin();
        cout << pp[f_index]*pp[s_index] << endl;
    }
    return 0;
}