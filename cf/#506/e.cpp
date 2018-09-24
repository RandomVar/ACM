#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+100;
vector<int>edge[maxn];
ll ans;
int dep[maxn];
int p[maxn];
int vis[maxn];
vector<int>vec;

void dfs(int u,int pre)
{
    p[u]=pre;
    dep[u]=dep[pre]+1;
    for(auto &v:edge[u])
    {
        if(v==pre) continue;
      dfs(v,u);
    }
}
int cmp(int x,int y)
{
return dep[x]>dep[y];
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
  
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
      vec.push_back(i);
    ans=0;
    dep[0]=-1;
   dfs(1,0);
   memset(vis,0,sizeof(vis));
   sort(vec.begin(),vec.end(),cmp);
     for(int i=0;i<n;i++)
     {
         if(vis[vec[i]]||dep[vec[i]]<=2) continue;
         ans++;
         vis[p[vec[i]]]=1;
        for(auto &v:edge[p[vec[i]]])
        {
            vis[v]=1;
        }
     }
    printf("%lld\n",ans);
}
}