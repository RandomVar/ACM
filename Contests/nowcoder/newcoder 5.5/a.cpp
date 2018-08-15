/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int sx,sy,tx,ty,n;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
int a[110][110];
struct node{
  int d,x,y;
  bool operator<(const node &b)const{
  return d>b.d;
  }
};
int d[110][110];
void dij(int sx,int sy){
	memset(d,0x3f,sizeof(d));
	d[sx][sy]=0;
	a[sx][sy]=0;
	a[tx][ty]=0;
	priority_queue<node>que;
	que.push(node{0,sx,sy});
	while(!que.empty()){
       node b=que.top();que.pop();
      for(int i=0;i<4;i++){
         int xx=b.x+dx[i];int yy=b.y+dy[i];
         if(xx<0||xx>=n||yy<0||yy>=n) continue;
		 if(d[xx][yy]>a[xx][yy]+d[b.x][b.y]) {
		 d[xx][yy]=a[xx][yy]+d[b.x][b.y];que.push(node{d[xx][yy],xx,yy});
	   }
	}
}}
/*
int dfs(int x,int y){
  if(x==tx&&y==ty) return 0;
  int ans=INF;
   for(int i=0;i<4;i++){
       int xx=x+dx[i];int yy=y+dy[i];
      if(xx<0||xx>=n||yy<0||yy>=n) continue;
      if(!vis[xx][yy]){
          vis[xx][yy]=1;
        cnt[xx][yy]=min(cnt[xx][yy],dfs(xx,yy)+a[x][y]);
         vis[xx][yy]=0;
         }
   }
return ans;
}*/
int main(){
//   int n;
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   while(cin>>n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
          cin>>a[i][j];
          if(a[i][j]==-1) {sx=i;sy=j;}
          else if(a[i][j]==-2) {tx=i;ty=j;}
   }
    // mem(vis);
     //vis[sx][sy]=1;
     dij(sx,sy);
     cout<<d[tx][ty]<<endl;
   }
   return 0;
}
/*
链接：https://www.nowcoder.com/acm/contest/118/A
来源：牛客网

5
6 6 0 -2 3
4 2 1 2 1
2 2 8 9 7
8 1 2 1 -1
9 7 2 1 2

5
62 33 18 -2 85
85 73 69 59 83
44 38 84 96 55
-1 11 90 34 50
19 73 45 53 95
*/
