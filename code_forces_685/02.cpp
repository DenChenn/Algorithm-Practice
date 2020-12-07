#include <iostream>
using namespace std;
char s[101];
char sub[101];
int main() {
  int t;
  cin >> t;
  while(t--){
    int n, q;
    cin >> n >> q;
    int l, r;
    for(int i=0;i<n;i++)
      cin >> s[i];
    for(int i=0;i<q;i++){
      cin >> l >> r;
      l--;
      r--;
      bool flag = 1;
      for(int i=0;i<l;i++){
        if(s[i] == s[l]){
          flag = 0;
          printf("YES\n");
          break;
        }
      }
      if(flag){
        for(int i=r+1;i<n;i++){
          if(s[r] == s[i]){
            flag = 0;
            printf("YES\n");
            break;
          }
        }
      }
      if(flag){
        printf("NO\n");
      }
    }
  }
}