#include<iostream>
#include<string>
using namespace std;

bool judge(string s1, string s2){
	if(s1 == s2)
		return true;
	else if(s1.length() == 1)
		return false;

	int l = s1.length();
	if(l % 2 == 0){
		string s1L = s1.substr(0, l/2);
		string s1R = s1.substr(l/2, l/2);
		string s2L = s2.substr(0, l/2);
		string s2R = s2.substr(l/2, l/2);

		if(judge(s1L, s2L) && judge(s1R, s2R))
			return true;
		else if(judge(s1L, s2R) && judge(s1R, s2L))
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	int t;
	string s1, s2;
	cin >> t;
	while(t--){
		cin >> s1 >> s2;
		if (s1.length() != s2.length()){
			cout << "No" << endl;
			continue;
		}
		if(judge(s1, s2))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}
