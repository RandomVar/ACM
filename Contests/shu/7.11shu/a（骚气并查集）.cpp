#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e4+100;
int daan[maxn];
int vis[1100][1100];
int sx[maxn],sy[maxn],tx[maxn],ty[maxn];
int cnt[1100][1100];
int p[1100*1100];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans;
void init()
{
    for(int i=0; i<=n*m+m; i++)
    {
        p[i]=i;
    }
    return;
}
int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}

int unin(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)//共父节点才能判断出关系
            return 0;
    p[x1]=y1;//连接两父节点
    return 1;
}


void dfs(int x,int y){
  vis[x][y]=1;
  for(int i=0;i<4;i++)
  {
      int xx=x+dx[i];int yy=y+dy[i];
      if(xx>0&&xx<=n&&yy>0&&yy<=m&&!vis[xx][yy]&&!cnt[xx][yy])
          {
              unin(x*m+y,xx*m+yy);
              dfs(xx,yy);
          }
  }
}
void gx(int x,int y){
  //vis[x][y]=1;
  for(int i=0;i<4;i++)
  {
      int xx=x+dx[i];int yy=y+dy[i];
      if(xx>0&&xx<=n&&yy>0&&yy<=m&&!cnt[xx][yy])
          {
              if(unin(x*m+y,xx*m+yy))
                  ans--;
              //dfs(xx,yy);
          }
  }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int q;
   while(cin>>m>>n>>q)
{
    init();
    mem(cnt,0);
    for(int i=1;i<=q;i++)
    {
        //int sx,sy,tx,ty;
        cin>>sy[i]>>sx[i]>>ty[i]>>tx[i];
        
        for(int x=sx[i];x<=tx[i];x++)
          for(int y=sy[i];y<=ty[i];y++)
          {
              cnt[x][y]++;
          }
    }
    mem(vis,0);
    ans=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
          {
              if(!cnt[i][j]&&!vis[i][j])
                  dfs(i,j),ans++;
          }
    daan[q]=ans;
    for(int i=q;i>=1;i--)
    {
        for(int x=sx[i];x<=tx[i];x++)
          for(int y=sy[i];y<=ty[i];y++)
          {
              cnt[x][y]--;
              if(!cnt[x][y]){
                ans++;
                gx(x,y);
              }
          }
          daan[i-1]=ans;
    }
    for(int i=1;i<=q;i++)
      cout<<daan[i]<<endl;
}

  }

