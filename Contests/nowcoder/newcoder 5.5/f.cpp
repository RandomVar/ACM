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
string s[510];
int vis[510][510];
int dx[]={0,0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1,0};
int n,m;
int check(int x,int y){//1 is boom!
    vis[x][y]=1;int cnt=0;
  for(int i=0;i<8;i++){
    int xx=x+dx[i];int yy=y+dy[i];
    if(xx<=0||xx>n||yy<0||yy>=m) continue;
    if(s[xx][yy]=='*') cnt++;
    else if(s[xx][yy]=='.'&&!vis[xx][yy]) cnt+=check(xx,yy);
  }
  s[x][y]=char('0'+cnt);
return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    //int n,m,k;
    int k;
    cin>>n>>m>>k;
    mem(vis);
    for(int i=1;i<=n;i++)
        cin>>s[i];
    int ans=-1;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
      if(ans==-1){
        if(s[x][y-1]>='1'&&s[x][y-1]<='9') {vis[x][y-1]=1;continue;}
        else if(s[x][y-1]=='*') {ans=i;}
        else check(x,y-1);
    }}
      if(ans==-1) {
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) cout<<s[i][j];
                else cout<<".";
            }
              cout<<endl;
        }
      }
      else cout<<"Game over in step "<<ans<<endl;
  }
  return 0;
}

