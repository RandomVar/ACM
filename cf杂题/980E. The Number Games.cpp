#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int st[maxn];
int ed[maxn];
int bit[maxn];
int  vis[maxn];
int fa[maxn];
vector<int>edge[maxn];
int tot;int n;
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=bit[x];
        x-=lowbit(x);
    }
    return ret;
}
void add(int x,int d)
{
    if(x<0) return;
    while(x<=n)
    {
        bit[x]+=d;
        x+=lowbit(x);
    }
}

void dfs(int u,int pre,int d)
{
    st[u]=++tot;
    fa[u]=pre;
    add(st[u],d);add(st[u]+1,-d);
    for(auto &v:edge[u])
    {
        if(v==pre) continue;
        dfs(v,u,d+1);
    }
    ed[u]=tot;
}
int main()
{
    int k;
    while(scanf("%d%d",&n,&k)==2)
    {
        tot=0;
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        dfs(n,0,1);
        int cnt=0;
        for(int i=n;i>=1;i--)
        {
            if(vis[i]) continue;
          int t=sum(st[i]);
          if(t+cnt<=n-k)
          {
              for(int u=i;u>0&&!vis[u];u=fa[u])
              {
                  vis[u]=1;
                  cnt++;
                  add(st[u],-1);add(ed[u]+1,1);
              }
          }
        }
        for(int i=1;i<=n;i++)
         if(!vis[i]) printf("%d ",i);
         printf("\n");
    }
}