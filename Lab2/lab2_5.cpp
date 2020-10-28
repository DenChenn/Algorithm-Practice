#include <iostream>
#include <vector>
#include<cstring>
#include<math.h>
#include<set>
using namespace std;

struct Store{
    long long x;
    long long y;
    double dis;
    long long order;
};

struct Two{
    long long first;
    long long second;
    double dis;
};

const Store Max = {40001, 40001, 0.0, -1};
const Two gg = {40001, 40001, 70000};
vector<Store> m;
vector<Two> record;
bool del[264143];
int ans = 0;

int lb(int l, int x, int left){
    int L = left;
    int R = l - 1;

    if(m[L].x >= x)
        return L;
    if(m[R].x < x)
        return -1;

    while(L + 1 != R){
        int mid = L + (R - L)/2;

        if(x <= m[mid].x)
            R = mid;
        else
            L = mid;
    }
    return R;
}

void Merge(int front, int mid, int end){

    vector<Store> LeftSub(m.begin()+front, m.begin()+mid+1),
                     RightSub(m.begin()+mid+1, m.begin()+end+1);

    LeftSub.push_back(Max);    
    RightSub.push_back(Max);   

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft].x <= RightSub[idxRight].x ) {
            m[i].x = LeftSub[idxLeft].x;
            m[i].y = LeftSub[idxLeft].y;
            m[i].dis = LeftSub[idxLeft].dis;
            m[i].order = LeftSub[idxLeft].order;
            idxLeft++;
        }
        else{
            m[i].x = RightSub[idxRight].x;
            m[i].y = RightSub[idxRight].y;
            m[i].dis = RightSub[idxRight].dis;
            m[i].order = RightSub[idxRight].order;
            idxRight++;
        }
    }
}

void MergeSort(int front, int end){
                                        
    if (front < end) {                   
        int mid = (front+end)/2;      
        MergeSort(front, mid);   
        MergeSort(mid+1, end);    
        Merge(front, mid, end);   
    }
}

void MergeX(std::vector<Two> &Array, int front, int mid, int end){
    std::vector<Two> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.push_back(gg);     
    RightSub.push_back(gg);   

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft].dis < RightSub[idxRight].dis) {
            //cout << "i: " << i << " " << 1 << endl;
            if(m[LeftSub[idxLeft].first].dis > m[LeftSub[idxLeft].second].dis){
                int t = LeftSub[idxLeft].first;
                LeftSub[idxLeft].first = LeftSub[idxLeft].second;
                LeftSub[idxLeft].second = t;
            }
            else if (m[LeftSub[idxLeft].first].dis == m[LeftSub[idxLeft].second].dis && 
                    m[LeftSub[idxLeft].second].order < m[LeftSub[idxLeft].first].order){   
                int t = LeftSub[idxLeft].first;
                LeftSub[idxLeft].first = LeftSub[idxLeft].second;
                LeftSub[idxLeft].second = t;
            }
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else if (LeftSub[idxLeft].dis == RightSub[idxRight].dis){
            //cout << "i: " << i << " " << 2 << endl;
            vector<int> temp;
            temp.push_back(LeftSub[idxLeft].first);
            temp.push_back(LeftSub[idxLeft].second);
            temp.push_back(RightSub[idxRight].first);
            temp.push_back(RightSub[idxRight].second);
            int min = 0;
            for(int i = 1;i < 4;i++){
                if(m[temp[min]].dis > m[temp[i]].dis)
                    min = i;
            }
            if(min == 0 || min == 1){
                if(m[temp[0]].dis > m[temp[1]].dis){
                    int t = LeftSub[idxLeft].first;
                    LeftSub[idxLeft].first = LeftSub[idxLeft].second;
                    LeftSub[idxLeft].second = t;
                }
                else if(m[temp[0]].dis == m[temp[1]].dis && m[temp[0]].order > m[temp[1]].order){
                    int t = LeftSub[idxLeft].first;
                    LeftSub[idxLeft].first = LeftSub[idxLeft].second;
                    LeftSub[idxLeft].second = t;
                }
                Array[i] = LeftSub[idxLeft];
                idxLeft++;
            }
            else{
                if(m[temp[2]].dis > m[temp[3]].dis){
                    int t = RightSub[idxLeft].first;
                    RightSub[idxRight].first = RightSub[idxRight].second;
                    RightSub[idxRight].second = t;
                }
                else if(m[temp[2]].dis == m[temp[3]].dis && m[temp[2]].order > m[temp[3]].order){
                    int t = RightSub[idxRight].first;
                    RightSub[idxRight].first = RightSub[idxRight].second;
                    RightSub[idxRight].second = t;
                }
                Array[i] = RightSub[idxRight];
                idxRight++;
            }

        }
        else{
            //cout << "i: " << i << " " << 3 << endl;
            if(m[RightSub[idxRight].first].dis > m[RightSub[idxRight].second].dis){
                int t = RightSub[idxRight].first;
                RightSub[idxRight].first = RightSub[idxRight].second;
                RightSub[idxRight].second = t;
            }
            else if (m[RightSub[idxRight].first].dis == m[RightSub[idxRight].second].dis && 
                    m[RightSub[idxRight].second].order < m[RightSub[idxRight].first].order){
                int t = RightSub[idxRight].first;
                RightSub[idxRight].first = RightSub[idxRight].second;
                RightSub[idxRight].second = t;
            }
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSortX(std::vector<Two> &array, int front, int end){
                                        
    if (front < end) {                   
        int mid = (front+end)/2;         
        MergeSortX(array, front, mid);   
        MergeSortX(array, mid+1, end);    
        MergeX(array, front, mid, end);
    }   
}

void find(){
    int l = m.size();
    int last;
    double dis;

    for(long long i = 0;i < l;i++){
        if(del[i])
            continue;

        last = lb(l, m[i].x + 200, i);
        if(last != -1){
            for(long long j = i+1;j < last;j++){
                if(del[j])
                    continue;
                if((m[j].x - m[i].x)*(m[j].x - m[i].x) + (m[j].y - m[i].y)*(m[j].y - m[i].y) < 40000){
                    dis = (m[j].x - m[i].x)*(m[j].x - m[i].x) + (m[j].y - m[i].y)*(m[j].y - m[i].y);
                    Two t = {i, j, dis};
                    record.push_back(t);
                }
            }
        }
        else{
            vector<int> temp;
            for(long long j = i+1;j < m.size();j++){
                if(del[j])
                    continue;
                if((m[j].x - m[i].x)*(m[j].x - m[i].x) + (m[j].y - m[i].y)*(m[j].y - m[i].y) < 40000){
                    dis = (m[j].x - m[i].x)*(m[j].x - m[i].x) + (m[j].y - m[i].y)*(m[j].y - m[i].y);
                    Two t = {i, j, dis};
                    record.push_back(t);
                }
            }
        }
    }
}


int main () {
    int num, a, b;
    double dis;
    cin >> num;
    memset(del, false, 40001);

    for(long long i = 0;i < num;i++){
        cin >> a >> b;
        dis = sqrt((20000 - a)*(20000 - a) + (20000 - b)*(20000 - b));
        Store temp = {a, b, dis, i};
        m.push_back(temp);
    }

    MergeSort(0, num-1);
    find();
    MergeSortX(record, 0, record.size()-1);
    int index = 0;
    
    int del[264143];
    fill_n(del, 264143, false);

    for(long long i = 0;i < record.size();i++){
        if(del[record[i].first] || del[record[i].second])
            continue;
        
        else{
            ans++;
            del[record[i].first] = true;
            continue;
        }
    }

    cout << "Number of removed 7-11 stores: " << ans << endl;

    return 0;
}