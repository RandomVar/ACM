#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
vector<int>edge[maxn];
int st[maxn];
int id[maxn];
int ed[maxn];
int tot;
int cnt[maxn];
int c[maxn];
int n;
ll ans[maxn];
ll sum[maxn];
int sz[maxn];
int t;
void add(int u)
{
    sum[++cnt[c[u]]]+=c[u];
    if(sum[t+1]>0) t++;
}
void del(int u)
{
    sum[cnt[c[u]]--]-=c[u];
    if(sum[t]==0) t--;
}
void getsz(int u,int pre)
{
    sz[u]=0;
    st[u]=++tot;
    id[tot]=u;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==pre) continue;
        getsz(v,u);
        sz[u]+=sz[v]+1;
    }
    ed[u]=tot;
}
void dfs(int u,int pre,int keep)
{
    int mx=-1;int bc=-1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v!=pre&&sz[v]>mx)
          mx=sz[v],bc=v;
    }
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v!=pre&&v!=bc)
          dfs(v,u,0);
    }
    if(bc!=-1)
     dfs(bc,u,1);
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v!=pre&&v!=bc)
        {
            for(int p=st[v];p<=ed[v];p++)
              add(id[p]);
        }
    }
    add(u);
    ans[u]=sum[t];
   // cal(c[u]);
   // cal(u);
    if(keep==0)
    {
       for(int p=st[u];p<=ed[u];p++)
         del(id[p]);
         //cnt[c[id[p]]]--;
    }
}
void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
     memset(cnt,0,sizeof(cnt));
     memset(sum,0,sizeof(sum));
     tot=0;
     t=0;
}
int main()
{
   
    while(scanf("%d",&n)==1)
    {
        init();
        for(int i=1;i<=n;i++)
         scanf("%d",&c[i]);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        getsz(1,0);
        dfs(1,0,0);
       for(int i=1;i<=n;i++)
         printf("%lld%c",ans[i],i==n?'\n':' ');
    }
}