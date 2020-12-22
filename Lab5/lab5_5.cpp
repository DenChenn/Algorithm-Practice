#include<bits/stdc++.h>
using namespace std;
int p1, p2, p3, p4, p5, p6;
int solve(){
		int sum=0;
		sum = p6 + p5 + p4;
		p1 -= min(p1,p5*11); // 把 5x5 剩下的格子放滿 1x1

		if(p2 < p4*5) //看看 4x4 的空位有沒有比 2x2 多，有的話剩下的放1*1
			p1 -= min(p1,(p4*5-p2)*4);
		p2 -= min(p2,p4*5); // 把 4x4 剩下的格子放滿 2x2
		p5 = p4 = 0;

		sum += ceil(p3/4.0);
		int p3_remain = p3 % 4;
        p3 %= 4;
		if(p3_remain == 1) { //可以放5個2x2 + 7個1x1
			if(p2 < 5) 
                p1 -= min(p1,(5-p2)*4);
			p1 -= min(p1,7);
			p2 -= min(p2,5);
		}
		if(p3_remain == 2) { //可以放3個2x2 + 6個1x1
			if(p2 < 3) 
                p1 -= min(p1,(3-p2)*4);
			p1 -= min(p1,6);
			p2 -= min(p2,3);
		}
		if(p3_remain == 3) { //可以放1個2x2 + 5個1x1
			if(!p2) 
                p1 -= min(p1,4);
			p1 -= min(p1,5);
			p2 -= min(p2,1);
		}

		sum += ceil(p2/9.0); //2x2還有
		int p2_remain = p2 % 9;
        p2 %= 9;
		if(p2_remain) 
            p1 -= min(p1,4*(9-p2)); //2x2開的心箱子還有空位
		sum += ceil(p1/36.0); //1x1還有
        return sum;
	}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	while(cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6&&(p1+p2+p3+p4+p5+p6)){
        cout << solve() << endl;
	}
    return 0;
}