#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e4+100;
typedef pair<int,int>P;
ll ans;
int rt;
int n,k;
vector<P>edge[maxn];
int d[maxn],sz[maxn],f[maxn];
vector<int>dep;
int vis[maxn];
int size;
void getroot(int u,int pre)
{
    sz[u]=1;
    f[u]=0;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(v==pre) continue;
        if(vis[v]) continue;
        getroot(v,u);
        sz[u]+=sz[v];
        f[u]=max(f[u],sz[v]);
    }
    f[u]=max(f[u],size-sz[u]);
    if(f[u]<f[rt]) rt=u;
}
void getdep(int u,int pre)
{
    dep.pb(d[u]);
    sz[u]=1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        int w=edge[u][i].sec;
        if(v==pre) continue;
        if(vis[v]) continue;
        d[v]=d[u]+w;
        getdep(v,u);
        sz[u]+=sz[v];
    }
}
int cal(int u,int c)
{
    dep.clear();
    d[u]=c;
    getdep(u,0);
    sort(dep.begin(),dep.end());
    int res=0;
    int l=0;int r=dep.size()-1;
    while(l<r)
    {
        if(dep[l]+dep[r]<=k)
           res+=r-l++;
        else r--;
    }
    return res;
}

void solve(int u)
{
    vis[u]=1;
    ans+=cal(u,0);
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].first;
        if(!vis[v])
        {
            ans-=cal(v,edge[u][i].second);
            f[0]=size=sz[v];
            getroot(v,rt=0);//找子树的重心
            solve(rt);
        }
    }
}
void init()
{
    for(int i=0;i<=n;i++)
      edge[i].clear();
      mem(vis,0);
      ans=0;
      rt=0;
     

}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  while(cin>>n>>k&&n&&k)
  { 
      init();
      for(int i=1;i<n;i++)
      {
          int u,v,w;
          cin>>u>>v>>w;
          edge[u].push_back(mpr(v,w));
          edge[v].push_back(mpr(u,w));
      }
      f[0]=size=n;
      getroot(1,rt=0);
      solve(rt);
     cout<<ans<<endl;
  }
 return 0;
  }

