#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+100;
ll sz[maxn];
int fa[maxn];
ll ans;ll res;
int n;
vector<int>edge[maxn];
void dfs1(int u,int pre)
{
    sz[u]=1;
    fa[u]=pre;
    for(auto &v:edge[u])
    {
       if(v==pre) continue;
       dfs1(v,u);
       sz[u]+=sz[v];
    }
}
void dfs(int u,int pre)
{
    for(auto &v:edge[u])
    {
        if(v==pre) continue;
        dfs(v,u);
        res+=sz[v]*(n-sz[v]);
    }
}
void solve(int u)
{
    for(auto &v:edge[u])
    {
        for(auto &w:edge[v])
        {
            if(w==u) continue;
            // ans+=sz[w]*(n-(sz[v]-sz[u])-sz[w]-1);
           if(u==fa[v])
           {
               ans+=sz[w]*(n-sz[u]+1);
           }
           else if(w==fa[v])
           {
                 ans+=sz[u]*(n-sz[w]+1);
           }
           else ans+=sz[w]*sz[u];
        }
    }
}

void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        init();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans=0;
        res=0;
        dfs1(1,0);
        dfs(1,0);
     for(int i=1;i<=n;i++)
        solve(i);
        cout<<res<<endl;
        printf("%lld\n",res-ans/2);
    }
}