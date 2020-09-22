#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main () {
    int t;
    cin >> t;
    getchar();
    while(t--){
        string s;
        getline(cin,s);
        if(s.length() == 0){
            cout << "Yes" << endl;
            continue;
        }
        stack<char> data;
        data.push(s[0]);
        for(int i = 1;i < s.length();i++){
            if(s[i] == ')' || s[i] == '(' || s[i] == '[' || s[i] == ']'){
                if(s[i] == ')' && !data.empty() && data.top() == '(')
                    data.pop(); 
                else if (s[i] == ']' && !data.empty() && data.top() == '[')
                    data.pop();         
                else
                    data.push(s[i]);
            }
        }

        if(data.empty()){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        while(!data.empty()){
            data.pop();
        }
    }
    return 0;
}