#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m[25][25];
struct Point {
    int count;
    int possi;
};

const Point minn = {-1,-1};

vector<Point> toFill;

int get_possi(int count, int l){
    int row = count / l;
    int col = count % l;
    int possi = 0;
	int i;
    for(i = 0;i < l;i++){
		if(m[i][col] != 0)
			possi++; 
	}

    for(i = 0;i < l;i++){
		if(m[row][i] != 0)
			possi++; 
	}

    int close_row = row / 3 * 3;
	int close_col = col / 3 * 3;
    for(i = close_row;i < close_row + 3;i++){
		for(int j = close_col;j < close_col + 3;j++){
			if(m[i][j] != 0)
				possi++;
		}
	} 
    return possi;
}

void get_point(int l){
    for(int i = 0;i < l;i++){
        for(int j = 0;j < l;j++){
            if(m[i][j] == 0){
                int count = i * l + j;
                Point temp = {count, get_possi(count, l)};
                toFill.push_back(temp);
            }
        }

    }
}


bool can_place(int count, int l){
	int row_now = count / l;
	int col_now = count % l;
	int i;

	for(i = 0;i < l;i++){
		if(m[i][col_now] == m[row_now][col_now] && i != row_now)
			return false; 
	}

	for(i = 0;i < l;i++){
		if(m[row_now][i] == m[row_now][col_now] && i != col_now)
			return false;
	}

	int close_row = row_now / 3 * 3;
	int close_col = col_now / 3 * 3;
	for(i = close_row;i < close_row + 3;i++){
		for(int j = close_col;j < close_col + 3;j++){
			if(m[i][j] == m[row_now][col_now] && i != row_now && j != col_now)
				return false;
		}
	} 
	return true;
}

void back(int index, int l, int& flag){
	if(index == toFill.size()){
		for(int i = 0;i < l;i++){
			for(int j = 0;j < l;j++)
				cout << m[i][j] << " "; 
			cout << endl;
		}
		flag = 1;
		return;
	}

	int row_now = toFill[index].count / l;
	int col_now = toFill[index].count % l;

	for(int i = 1;i <= l;i++){
		m[row_now][col_now] = i;
		if(can_place(toFill[index].count, l)){
			back(index+1, l, flag);
		}
	}
	m[row_now][col_now] = 0;

}

void Merge(std::vector<Point> &Array, int front, int mid, int end){

    std::vector<Point> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.push_back(minn);     
    RightSub.push_back(minn);   
    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft].possi >= RightSub[idxRight].possi ) {
            Array[i].count = LeftSub[idxLeft].count;
            Array[i].possi = LeftSub[idxLeft].possi;
            idxLeft++;
        }
        else{
            Array[i].count = RightSub[idxRight].count;
            Array[i].possi = RightSub[idxRight].possi;
            idxRight++;
        }
    }
}

void MergeSort(std::vector<Point> &array, int front, int end){
                                         
    if (front < end) {                  
        int mid = (front+end)/2;         
        MergeSort(array, front, mid);   
        MergeSort(array, mid+1, end);    
        Merge(array, front, mid, end);  
    }
}

int main () {
	string first;
	getline(cin, first);
	int l = (first.length() + 1) / 2;
	int index = 0;
	for(int i = 0;i < l;i++){
		for(int j = 0;j < l;j++){
			m[i][j] = first[index] - 48;
			index += 2;
		}
		index = 0;
		getline(cin, first);
	}
	int flag = 0;
    get_point(l);
    MergeSort(toFill, 0, toFill.size()-1);
	back(0, l, flag);
	
	if(flag == 0)
		cout << "NO" << endl;
	return 0;
}
