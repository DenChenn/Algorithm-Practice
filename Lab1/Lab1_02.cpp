#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int length, temp;
        set<int> data;
        map<int,int> mp;
        int repeat_most = 0;
        
        cin >> length;
        if(length < 2){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0;i < length;i++){
            cin >> temp;
            data.insert(temp);
            mp[temp]++;
        }
        for(auto a : mp){
            if(repeat_most < a.second)
                repeat_most = a.second;
        }
        
        int distinct_most = data.size();

        if(repeat_most <= distinct_most)
            cout << repeat_most << endl;
        else
            cout << distinct_most << endl;
    }
    return 0;
}