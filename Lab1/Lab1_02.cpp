#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long length, temp;
        set<long long> data;
        map<long long,long long> mp;
        long long repeat_most = 0;
        
        cin >> length;
        if(length < 2){
            for(int i = 0;i < length;i++){
                cin >> temp;
            }
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
        
        long long distinct_most = data.size();
        distinct_most--;

        if(repeat_most <= distinct_most)
            cout << repeat_most << endl;
        else if(repeat_most - distinct_most >= 2)
            cout << distinct_most + 1 << endl;
        else
            cout << distinct_most << endl;

        data.clear();
        mp.clear();

    }
    return 0;
}