#include <iostream>
#include <vector>
using namespace std;

struct P{
	int x;
	int y;
};

const P MAX = {10001, 10001};
void Merge(vector<P> &arr, int front, int mid, int end);

void Merge(vector<P> &arr, int front, int mid, int end){
	vector<P> left(arr.begin() + front, arr.begin() + mid + 1);
	vector<P> right(arr.begin() + mid + 1, arr.begin() + end + 1);
	
	left.push_back(MAX);
	right.push_back(MAX);
	
	int idl = 0, idr = 0;
	
	for(int i = front;i <= end;i++){
		int valuel = left[idl].x * left[idl].x + left[idl].y * left[idl].y;
		int valuer = right[idr].x * right[idr].x + right[idr].y * right[idr].y;
		
		if(valuel <= valuer){
			arr[i].x = left[idl].x;
			arr[i].y = left[idl].y;
			idl++;
		}
		else{
			arr[i].x = right[idr].x;
			arr[i].y = right[idr].y;
			idr++;
		}
	}

} 

void MgS(vector<P> &arr, int front, int end){
	if (front < end) {
		int mid = (front + end) / 2;
		MgS(arr, front, mid);
		MgS(arr, mid+1, end);
		Merge(arr, front, mid, end);
	}
}

void MergeA(vector<P> &arr, int front, int mid, int end){
	vector<P> left(arr.begin() + front, arr.begin() + mid + 1);
	vector<P> right(arr.begin() + mid + 1, arr.begin() + end + 1);
	
    P min = {-10001, -10001};	
	left.push_back(min);
	right.push_back(min);
	
	int idl = 0, idr = 0;
	
	for(int i = front;i <= end;i++){
			
		if(left[idl].x > right[idr].x){
			arr[i].x = left[idl].x;
			arr[i].y = left[idl].y;
			idl++;
		}
		else if(left[idl].x < right[idr].x){
			arr[i].x = right[idr].x;
			arr[i].y = right[idr].y;
			idr++;
		}
		else{
			if(left[idl].y >= right[idr].y){
				arr[i].x = left[idl].x;
				arr[i].y = left[idl].y;
				idl++;
			}
			else{
				arr[i].x = right[idr].x;
				arr[i].y = right[idr].y;
				idr++;
			}
		}
	}
} 

void MgSA(vector<P> &arr, int front, int end){
	if (front < end) {
		int mid = (front + end) / 2;
		MgSA(arr, front, mid);
		MgSA(arr, mid+1, end);
		MergeA(arr, front, mid, end);
	}
}

int main() {
	int n, tar;
	cin >> n >> tar;
	vector<P> data;
	int a, b;
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		P temp = {a, b};
		data.push_back(temp);
	}
    
	MgS(data, 0, n-1);	
	
	vector<P> ans;	
	for(int i = 0;i < tar;i++)
		ans.push_back(data[i]);
	MgSA(ans, 0, tar-1);
	
	for(auto a : ans)
		cout << a.x << " " << a.y << endl;
	return 0;
}




