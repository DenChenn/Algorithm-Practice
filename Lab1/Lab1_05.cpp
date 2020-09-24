#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int a1[100001];

int main () {
    int t;
    cin >> t;
    while(t--){
        fill_n(a1, 100001, 0);
        vector<int> ensure, leave;

        int l1, l2, temp;
        unordered_map<int,int> mp;

        cin >> l1 >> l2;
        for(int i = 0;i < l1;i++){
            cin >> temp;
            a1[i] = temp;
        }
        for(int i = 0;i < l2;i++){
            cin >> temp;
            ensure.push_back(temp);
            mp[temp] = 0;
        }

        for(int i = 0;i < l1;i++){
            if(mp.count(a1[i]))
                mp[a1[i]]++;
            else
                leave.push_back(a1[i]);
        }
        sort(leave.begin(),leave.end());


        for(int i = 0;i < ensure.size();i++){
            for(int j = 0;j < mp[ensure[i]];j++)
                cout << ensure[i] << " ";
        }
        
        if(leave.size() != 0){
            for(int i = 0;i < leave.size();i++)
                cout << leave[i] << " ";
            cout << endl;
        }
        else{
            cout << endl;
        }

        mp.clear();
        leave.clear();
        ensure.clear();
    }
    return 0;
}