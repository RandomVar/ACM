#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+100;
const ll mod=998244353;
vector<int>edge[maxn];
int vis[maxn];
int cnt[3];
ll p[maxn];
void init()
{
    p[0]=1;
    for(int i=1;i<maxn;i++)
     p[i]=p[i-1]*2%mod;
}
int dfs(int id,int flag)
{
    vis[id]=flag;
    cnt[flag]++;
    for(int i=0;i<edge[id].size();i++)
    {
        int v=edge[id][i];
       if(vis[v]==flag)
            return 0;
      if(vis[v]==-1)
         if(!dfs(v,flag^1)) return 0;
    }
    return 1; 
}
int main()
{
  int t;
  cin>>t;
  init();
  while(t--)
  {
      int n,m;
      cin>>n>>m;
      for(int i=0;i<n+10;i++)
       {
       edge[i].clear();
       vis[i]=-1;
       }
      ll ans=1;
      for(int i=1;i<=m;i++)
      {
          int u,v;
          cin>>u>>v;
          edge[u].push_back(v);
          edge[v].push_back(u);
      }
      for(int i=1;i<=n;i++)
      {
        cnt[1]=cnt[0]=0;
       if(vis[i]==-1) 
       {
           if(dfs(i,1)==0) 
           {
               ans=0;
               break;
           }
           if(cnt[0]==0)
             ans=ans*3%mod;
           else ans=(ans*(p[cnt[1]]+p[cnt[0]])%mod)%mod;
        }
      }
      cout<<ans<<endl;
  }
}