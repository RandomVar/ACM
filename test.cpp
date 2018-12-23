#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=4000;
const int inf=1e9;
struct E{
    int to,cap;
    int rev;
};
vector<E>edge[maxn];
int level[maxn];
void addedge(int u,int v,int cap)
{
    edge[u].push_back((E){v,cap,edge[v].size()});
    edge[v].push_back((E){u,0,edge[u].size()-1});
}
void bfs(int s)
{
  memset(level,-1,sizeof(level));
  level[s]=0;
  queue<int>que;
  que.push(s);
  while(!que.empty())
  {
      int u=que.front();
      que.pop();
      for(int i=0;i<edge[u].size();i++)
      {
          E e=edge[u][i];
          if(e.cap>0&&level[e.to]==-1)
          {
              level[e.to]=level[u]+1;
              que.push(e.to);
          }
      }
  }
}
int dfs(int u,int t,int f)
{
    if(u==t) return f;
    for(int i=0;i<edge[u].size();i++)
    {
        E e=edge[u][i];
        if(level[e.to]==level[u]+1&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                edge[u][i].cap-=d;
                edge[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        bfs(s);
      if(level[t]<0) return flow;
     int f;
     while((f=dfs(s,t,inf))>0)
     {
         flow+=f;
     }  
    }
    return flow;
}
char a[40][40];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int value[30];
 main()
{
  int n,m,c;
  while(scanf("%lld%lld%lld",&n,&m,&c)==3)
  {
      for(int i=1;i<=n;i++)
       scanf("%s",a[i]+1);
      for(int i=1;i<=c;i++)
        scanf("%d",&value[i]);
       int s;int t=2*n*(m+1)+10;
       for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
          if(a[i][j]=='B') 
            {
               s=2*(i*m+j);
               addedge(s,s+1,inf);
            }
          else if(a[i][j]=='.')
          {
            int c=2*(i*m+j);
            addedge(c,c+1,inf);
          }
          else
          {
              int c=2*(i*m+j);
              addedge(c,c+1,value[a[i][j]-'a'+1]);
          }
        }
        for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++)
          {
              int id1=2*(i*m+j)+1;
              for(int c=0;c<4;c++)
              {
                  int xx=i+dx[c];
                  int yy=j+dy[c];
                  if(xx<1||xx>n) continue;
                  if(yy<1||yy>m) continue;
                  int id2=2*(xx*m+yy);
                  addedge(id1,id2,inf);
              }
              if(i==1||j==1||i==n||j==m)
                addedge(id1,t,inf);
          }
          int ans=max_flow(s,t);
          if(ans>=inf)
            printf("-1\n");
          else printf("%lld\n",ans);
  }
}

