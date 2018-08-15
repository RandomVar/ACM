#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int ux,uy,vx,vy;
int n;
const int maxn=17;
int vis[maxn][maxn];
struct node{
 int x,y,st;

};
string s[maxn];
int dis[maxn][maxn];
int dp[(1<<maxn)][maxn];
bool check(int x,int y){
 if(x<0||x>=n||y<0||y>=n) return 0;
 if(vis[x][y]) return 0;
 if(s[x][y]=='#') return 0;
return 1;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct ed{
  int sx,sy,tx,ty;

}t[20];
int bfs(){
    memset(vis,0,sizeof(vis));
  queue<node>que;
  que.push(node{ux,uy,0});
  vis[ux][uy]=1;
  while(!que.empty()){

     node e=que.front();
 // cout<<e.x<<" "<<e.y<<endl;
 if(e.x==vx&&e.y==vy) return e.st;
     que.pop();
     for(int i=0;i<4;i++){
        int xx=e.x+dx[i];
        int yy=e.y+dy[i];

        if(check(xx,yy)){

             que.push(node{xx,yy,e.st+1});
            vis[xx][yy]=1;
        }
     }
  }
return -1;
}
int main(){
  int m;
  while(cin>>n>>m){
  for(int i=0;i<n;i++)
     cin>>s[i];
  for(int i=0;i<m;i++){
     cin>>t[i].sx>>t[i].sy>>t[i].tx>>t[i].ty;
  }
  for(int i=0;i<m;i++){
     ux=t[i].tx-1;uy=t[i].ty-1;
     for(int j=0;j<m;j++){
        if(i!=j){
          vx=t[j].sx-1;vy=t[j].sy-1;
          dis[i][j]=bfs();
         // cout<<dis[i][j]<<endl;
       }
       else dis[i][i]=0;
    }
    }
     int ans=INF;
     memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<m;i++)
        dp[(1<<i)][i]=0;
      for(int s=0;s<(1<<m);s++){
        for(int u=0;u<m;u++){
          if(dp[s][u]!=INF)
            for(int v=0;v<m;v++){
             if((s&(1<<v))==0&&dis[u][v]!=-1)
                dp[s|(1<<v)][v]=min(dp[s|(1<<v)][v],dp[s][u]+dis[u][v]);

            }
        }
    }
   for(int i=0;i<m;i++)
    ans=min(ans,dp[(1<<m)-1][i]);
   if(ans==INF) cout<<-1<<endl;
   else cout<<ans<<endl;
  }
}
