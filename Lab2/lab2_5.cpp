#include <iostream>
#include <vector>
#include<cstring>
#include<math.h>
#include<set>
using namespace std;

struct Store{
    int x;
    int y;
    double dis;
    int order;
};

struct Two{
    int first;
    int second;
    double dis;
};

const Store Max = {40001, 40001, 0.0, -1};
const Two gg = {40001, 40001, 70000};
vector<Store> m;
vector<Two> record;
bool del[40001];
int ans = 0;

int lb(int l, int x, int left){
    int L = left;
    int R = l - 1;

    if(m[L].x >= x)
        return L;
    if(m[R].x < x)
        return -1;

    while(L + 1 != R){
        int mid = (L + R) / 2;

        if(x <= m[mid].x)
            R = mid;
        else
            L = mid;
    }
    return R;
}

int lbX(int l, double x, int left){
    int L = left;
    int R = l - 1;

    if(record[L].dis > x)
        return L;
    if(record[R].dis < x)
        return -1;

    while(L + 1 != R){
        int mid = (L + R) / 2;

        if(x <= record[mid].dis)
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

        if (LeftSub[idxLeft].dis <= RightSub[idxRight].dis ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
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

    for(int i = 0;i < l;i++){
        if(del[i])
            continue;

        last = lb(l, m[i].x + 200, i);
        if(last != -1){
            for(int j = i+1;j < last;j++){
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
            for(int j = i+1;j < m.size();j++){
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

    for(int i = 0;i < num;i++){
        cin >> a >> b;
        dis = sqrt((20000 - a)*(20000 - a) + (20000 - b)*(20000 - b));
        Store temp = {a, b, dis, i};
        m.push_back(temp);
    }

    MergeSort(0, num-1);
    find();
    MergeSortX(record, 0, record.size()-1);

    set<int> del;
    int index = 0;
    
    while(index < record.size()){
        int have_del = 0;
        if(del.count(record[index].first) == 1 || del.count(record[index].second) == 1){
            //cout << "index: " << index << endl;
            index++;
            continue;
        }
        //cout << "inin" << endl;

        int bound = lbX(record.size(), record[index].dis+0.1, index+1);
        //cout << "bound " << bound << endl;
        if(bound == index + 1 || bound == -1){
            if(m[record[index].first].dis < m[record[index].second].dis){
                //cout << "1" << endl;
                del.insert(record[index].first);
                ans++;
                have_del = 1;
            }
            else if(m[record[index].first].dis > m[record[index].second].dis){
                //cout << "2" << endl;
                del.insert(record[index].second);
                ans++;
                have_del = 1;
            }
            else{
                if(m[record[index].first].order < m[record[index].second].order){
                    //cout << "3" << endl;
                    del.insert(record[index].first);
                    ans++;
                    have_del = 1;
                }
                else{
                    //cout << "4" << endl;
                    del.insert(record[index].second);
                    ans++;
                    have_del = 1;
                }
            }
        }
        else{
            int tar_index = index;
            int tar_dis = m[record[index].first].dis;

            for(int i = index+1;i < bound;i++){
                //cout << "i: " << i << endl; 
                if(del.count(record[i].first) == 1 || del.count(record[i].second) == 1)
                    continue;
                
                if(tar_dis > m[record[i].first].dis){
                    //cout << "6" << endl;
                    tar_index = record[i].first;
                }
                else if(tar_dis == m[record[i].first].dis){
                    if(m[tar_index].order > m[record[i].first].order){
                        //cout << "7" << endl;
                        tar_index = record[i].first;
                        tar_dis = m[record[i].first].dis;

                    }
                }
                if(tar_dis > m[record[i].second].dis){
                    //cout << "8" << endl;
                    tar_index = record[i].second;
                }
                else if(tar_dis == m[record[i].second].dis){
                    if(m[tar_index].order > m[record[i].second].order){
                        //cout << "6" << endl;
                        tar_index = record[i].second;
                        tar_dis = m[record[i].second].dis;

                    }
                }
            }
            have_del = 1;
            del.insert(tar_index);
            ans++;
            
        }
        if(have_del == 0){
            cout << "break" << endl;
            break;
        }
    }

    cout << "Number of removed 7-11 stores: " << ans << endl;

    return 0;
}