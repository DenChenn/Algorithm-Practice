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

        int l1, l2, temp;
        unordered_map<int,int> mp;

        cin >> l1 >> l2;
        for(int i = 0;i < l1;i++){
            cin >> temp;
            a1[i] = temp;
        }
        for(int i = 0;i < l2;i++){
            cin >> temp;
            mp[temp] = 0;
        }

        vector<int> leave, rev;
        for(int i = 0;i < l1;i++){
            if(mp.count(a1[i]))
                mp[a1[i]]++;
            else
                leave.push_back(a1[i]);
        }
        sort(leave.begin(),leave.end());


        for(auto a : mp){
            for(int i = 0;i < a.second;i++)
                rev.push_back(a.first);
        }
        for(int i = rev.size() - 1;i >= 0;i--)
            cout << rev[i] << " ";
        
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
        rev.clear();
    }
    return 0;
}