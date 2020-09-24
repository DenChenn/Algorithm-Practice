#include <iostream>
#include <vector>
#include <string>
using namespace std;
string m = "-1";

bool c1_is_larger(string& c1, string& c2){
    if(c1.length() > c2.length())
        return true;
    else if(c1.length() < c2.length())
        return false;

    for(int i = 0;i < c1.length();i++){
        if(c1[i] > c2[i])
            return true;
        else if(c1[i] < c2[i])
            return false;
        else
            continue;
    }
    return true;
}

void my_merge(vector<string>& v, int front, int mid, int end){
    vector<string> left_v(v.begin()+front, v.begin()+mid+1);
    vector<string> right_v(v.begin()+mid+1, v.begin()+end+1);

    left_v.push_back(m);
    right_v.push_back(m);

    int l_index = 0, r_index = 0;
    string c1, c2;

    for(int i = front;i <= end;i++){
        c1 = left_v[l_index] + right_v[r_index];
        c2 = right_v[r_index] + left_v[l_index];

        if(c1_is_larger(c1,c2)){
            v[i] = left_v[l_index];
            l_index++;
        }
        else{
            v[i] = right_v[r_index];
            r_index++;
        }
    }

}

void my_merge_sort(vector<string>& v, int front, int end){
    if (front < end){
        int mid = (front + end) / 2;
        my_merge_sort(v, front, mid);
        my_merge_sort(v, mid+1,end);
        my_merge(v, front, mid, end);
    }
}

int main () {
    int t;
    cin >> t;
    while(t--){
        int length;
        cin >> length;
        vector<string> data;
        string temp;
        for(int i = 0;i < length;i++){
            cin >> temp;
            data.push_back(temp);
        }
        my_merge_sort(data, 0, length-1);
        for(auto a : data)
            cout << a;
        cout << endl;
    }
    return 0;
}