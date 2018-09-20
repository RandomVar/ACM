#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
vector<pair<int,int> >edge[maxn];
int dian[maxn];
ll dis[45][45];
ll di[maxn];

vector<int> sp;
int dep[maxn], dfn[maxn];
pair<int,int> dp[21][maxn << 1];
int p[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++) edge[i].clear();
    sp.clear();
    memset(dis,0x3f,sizeof(dis));
    di[1]=0;
    for(int i=0; i<=n; i++)
        p[i]=i;
}

int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}

int Union(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)
        return 0;
    p[x1]=y1;
      return 1;
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (int i=0;i<edge[u].size();i++)
    {
      pair<int,int> v=edge[u][i];
        if (v.fir == fa) continue;
         di[v.fir]=di[u]+v.sec;
        dfs(v.fir, u);
        sp.push_back(u);
    }
}
void initrmq()
{
    int n = sp.size();
    for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).sec;
}
ll solve(int u,int v)
{
  int x=lca(u,v);
  return di[u]+di[v]-2*di[x];
  // ?  return min(lca(u,v))
}
int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
      map<int,int>mp;
      init(n);
      int k=0;
      int u,v;ll d;
      for(int i=1;i<=m;i++)
      {
       scanf("%d%d%lld",&u,&v,&d);
        if(Union(u,v)==0)
        {
          if(!mp.count(u))  mp[u]=++k,dian[k]=u;
          if(!mp.count(v)) mp[v]=++k,dian[k]=v;
            dis[mp[u]][mp[v]]=d;
           dis[mp[v]][mp[u]]=d;
         }
         else
         {
       edge[u].push_back(mkr(v,d));
       edge[v].push_back(mkr(u,d));
        }
     }
      for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
         for(int s=1;s<=k;s++)
          dis[i][s]=min(dis[i][s],dis[i][j]+dis[j][s]);
    dfs(1,0);
    initrmq();
    for(int i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
        ll ans=INF;
        ans=solve(u,v);
      for(int j=1;j<=k;j++)
       for(int s=1;s<=k;s++)
      {
        // if(j==s) continue;

        ans=min(ans,solve(u,dian[s])+solve(v,dian[j])+dis[j][s]);
        ans=min(ans,solve(u,dian[j])+solve(v,dian[s])+dis[j][s]);
      }
        printf("%lld\n",ans);
    }

     }
 return 0;
  }
