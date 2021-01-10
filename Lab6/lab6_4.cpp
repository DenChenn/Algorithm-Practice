#include <bits/stdc++.h>
using namespace std;
bool visited[1010];
int vn;
int max_r;

struct V{
    int x; int y; double t; int r;
};

vector<V> bird;

void bfs(int reward, double now_time, int now_x, int now_y){
    //cout << now_x << " " << now_y << endl;
    bool have_adj = false;
    double dis;
    for(int i = 0;i < vn;i++){
        //cout << "i: " << i << endl;
        if(!visited[i]){
            dis = sqrt((bird[i].x-now_x)*(bird[i].x-now_x)+(bird[i].y-now_y)*(bird[i].y-now_y));
            if(now_time + dis <= bird[i].t){
                have_adj = true;
                visited[i] = true;
                bfs(reward+bird[i].r, bird[i].t, bird[i].x, bird[i].y);
                visited[i] = false;       
            }
        }
    }
    if(!have_adj && max_r < reward){
            //cout << "reward: " << reward << endl;
            //cout << "off" << endl;
            max_r = reward;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int time;
    cin >> time;
    while(time--){
        fill_n(visited, 1010, false);
        max_r = 0;
        bird.clear();
        cin >> vn;
        for(int i = 0;i < vn;i++){
            V v;
            cin >> v.x >> v.y >> v.t >> v.r;
            bird.push_back(v);
        }
        for(int s = 0;s < vn;s++){
            //cout << "start" << endl;
            visited[s] = true;
            bfs(bird[s].r, 0.0, bird[s].x, bird[s].y);
            visited[s] = false;
        }
        cout << max_r << endl;
    }
    return 0;
}