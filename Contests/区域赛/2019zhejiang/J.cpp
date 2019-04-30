#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int par[maxn],vis[maxn],inq[maxn];
priority_queue<int,vector<int>,greater<int> > q;
vector<int> G[maxn];
int n,m;
int find(int x)
{
  if(par[x]==x) return x;
  return par[x]=find(par[x]);
}
void uni(int A,int B)
{
  int x=find(A),y=find(B);
  if(x==y) return ;
  par[x]=y;
}
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;++i)
    {
      par[i]=i;
      G[i].clear();
    }
    for(int i=0;i<m;++i)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      uni(a,b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    memset(vis,0,sizeof(vis)*(n+2));
    memset(inq,0,sizeof(inq)*(n+2));
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
      int rt=find(i);
      if(vis[rt]) continue;
      vis[rt]=1;
      inq[i]=1;
      q.push(i);
      ++cnt;
    }
    printf("%d\n",cnt);
    while(!q.empty())
    {
      int id=q.top();q.pop();
      printf("%d",id);
      for(int i=0;i<G[id].size();++i)
      {
        int v=G[id][i];
        if(inq[v]) continue;
        inq[v]=1;
        q.push(v);
      }
      if(!q.empty()) printf(" ");
    }
    printf("\n");
  }
  return 0;
}