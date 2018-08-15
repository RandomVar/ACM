#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
char d[]={'N','W','S','E'};
int dy[]={1,0,-1,0};
int dx[]={0,-1,0,1};
string s[1010];
int vis[1010][1010][5];
ll ans[1010][1010][5];
ll mod;
int  r2,c2;
int n,m;
struct node{
  int u;int v;int d;int st;

};
bool check(int u,int v){
 if(u<0||u>=n||v<0||v>=m) return 0;
 if(s[u][v]=='*') return 0;
 return 1;

}
ll bfs(int u,int v,int s){
  queue<node>que;
  que.push(node{u,v,s,1});
  vis[u][v][s]=1;
  ans[u][v][s]=1;
  while(!que.empty()){
     node e=que.front();
     que.pop();
     //if(e.u==r2&&e.v==c2) continue;
     if(!vis[e.u][e.v][(e.d+1)%4])
     {
         vis[e.u][e.v][(e.d+1)%4]=e.st+1;
         ans[e.u][e.v][(e.d+1)%4]+=ans[e.u][e.v][e.d];
         que.push(node{e.u,e.v,(e.d+1)%mod,e.st+1});
     }
     else if(vis[e.u][e.v][(e.d+1)%4]==e.st+1){
        ans[e.u][e.v][(e.d+1)%4]=(ans[e.u][e.v][e.d]+ans[e.u][e.v][(e.d+1)%4])%mod;
     }
     if(!vis[e.u][e.v][(e.d-1)%4])
     {
         vis[e.u][e.v][(e.d-1)%4]=e.st+1;
          ans[e.u][e.v][(e.d-1)%4]+=ans[e.u][e.v][e.d];
         que.push(node{e.u,e.v,(e.d-1)%mod,e.st+1});
     }
     else if(vis[e.u][e.v][(e.d-1)%4]==e.st+1){
        ans[e.u][e.v][(e.d-1)%4]=(ans[e.u][e.v][e.d]+ans[e.u][e.v][(e.d-1)%4])%mod;
     }

      if(check(e.u+dx[e.d],e.v+dy[e.d])&&!vis[e.u+dx[e.d]][e.v+dy[e.d]][e.d])
     {
          ans[e.u+dx[e.d]][e.v+dy[e.d]][e.d]+=ans[e.u][e.v][e.d];
         vis[e.u+dx[e.d]][e.v+dy[e.d]][e.d]=e.st+1;
         que.push(node{e.u+dx[e.d],e.v+dy[e.d],e.d,e.st+1});
     }
     else if(check(e.u+dx[e.d],e.v+dy[e.d])&&vis[e.u+dx[e.d]][e.v+dy[e.d]][e.d]==e.st+1){
         ans[e.u+dx[e.d]][e.v+dy[e.d]][e.d]=(ans[e.u][e.v][e.d]+ans[e.u+dx[e.d]][e.v+dy[e.d]][e.d])%mod;

     }

  }
  return ((ans[r2][c2][0]+ans[r2][c2][1])%mod+(ans[r2][c2][2]+ans[r2][c2][3])%mod)%mod;
}
int main(){
  while(cin>>n>>m>>mod){
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
     for(int i=0;i<n;i++)
        cin>>s[i];
     int r1,c1;
     //int r2,c2;
     cin>>r1>>c1>>r2>>c2;
     char c;cin>>c;
     //cout<<c<<endl;
     int cc;
     for(int i=0;i<4;i++)
        if(c==d[i]) cc=i;

     ll xx=bfs(r1,c1,cc);
     if(xx==0) cout<<-1<<endl;
     else cout<<xx<<endl;
  }
}
