#include <iostream>
#include <algorithm>
using namespace std;
int arr[1048577];

int BinaryS(int a[], int tar, int l, int r){
    if(r >= l){
        int mid = l + (r - l)/2;

        if(a[mid] == tar)
            return mid;
        if(a[mid] > tar)
            return BinaryS(a, tar, l, mid-1);
        else
            return BinaryS(a, tar, mid+1, r); 
    }
    return -1;
}

int main () {
    int l, t, tar, ans, pivot = 0;
    cin >> l >> t;
    for(int i = 0;i < l;i++){
        cin >> arr[i];
        if(i != 0 && arr[i] < arr[i-1])
            pivot = i;
    }
    int len1, len2;
    len1 = pivot;
    len2 = l - pivot;

    sort(arr, arr+l);
    while(t--){
        cin >> tar;
        ans = BinaryS(arr, tar, 0, l-1);
        if(ans == -1){
            cout << ans << endl;
            continue;
        }
        if(ans >= len2)
            ans -= len2;
        else
            ans += len1;
        cout << ans << endl;
    }
    return 0;
}