#include <bits/stdc++.h>
using namespace std;
int s[1001];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, c0, c1, h;
    int t;
    int st0, st1, ct0, ct1;
    cin >> t;
    while(t--){
        int sum = 0;
        string temp;
        cin >> n >> c0 >> c1 >> h;
        cin >> temp;
        for(int i = 0;i < n;i++)
            s[i] = temp[i] - 48;
        
        st0 = c0;
        st1 = c1;
        ct0 = c0 + h;
        ct1 = c1 + h;
        //cout << c0 << "---" << c1 << endl;
        //cout << st0 << " " << st1 << " " << ct0 << " " << ct1 << endl;
        for(int i = 0;i < n;i++){
            if(s[i] == 0){
                if(st0 < ct1)
                    sum += st0;
                else
                    sum += ct1;
            }
            else{
                if(st1 < ct0)
                    sum += st1;
                else
                    sum += ct0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}