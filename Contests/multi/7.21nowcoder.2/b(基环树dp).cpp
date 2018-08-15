<https://blog.csdn.net/u013578420/article/details/81156116>

#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
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
int m;
vector<int>edge[maxn];
int inc[maxn];
vector<int>cir[maxn];
int vis[maxn];
int p[maxn],d[maxn],f[maxn];
int fa[maxn];
ll dp[maxn][2];
ll sum[maxn];
ll g[maxn][2];
int cnt;
void dfs(int u)
{
    vis[u]=cnt;
   for(int i=0;i<edge[u].size();i++)
   {
       int v=edge[u][i];
       if(vis[v]==cnt)
       { 
          m++;
         for(int x=u;x!=v;x=fa[x])
          {
              inc[x]=1;
              cir[m].pb(x);
          }
           inc[v]=1;
           cir[m].pb(v);
           continue;
       }
       fa[v]=u;
       if(!vis[v]) dfs(v);
   }
}

void DP(int u)
{
     vis[u]=1;
     for(int i=0;i<edge[u].size();i++)
     {
         int v=edge[u][i];
         if(!vis[v]) DP(v);
         if(inc[v]) continue;
         sum[u]+=dp[v][0];
     }     
     dp[u][1]=p[u]+sum[u];
     dp[u][0]=p[u]-d[u]+sum[u];
     for(int i=0;i<edge[u].size();i++)
     {
         int v=edge[u][i];
         if(inc[v]) continue;
         dp[u][0]=min(dp[u][0],dp[v][1]+sum[u]-dp[v][0]);
     }
}
void init(int n)
{
   for(int i=0;i<=n;i++)
    {
    edge[i].clear();
    inc[i]=sum[i]=0;
    cir[i].clear();
    }
    cnt=m=0;
} 

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       init(n);
       for(int i=1;i<=n;i++)
        cin>>p[i];
        for(int i=1;i<=n;i++)
         cin>>d[i];
        for(int i=1;i<=n;i++)
         {
         cin>>f[i];
         edge[f[i]].pb(i);
         }
         mem(vis,0);
       // cout<<1<<endl;
        for(int i=1;i<=n;i++)
        if(!vis[i]) {cnt++;dfs(i);}
      //   cout<<1<<endl;
        mem(vis,0);
        for(int i=1;i<=n;i++)
          if(!vis[i]) DP(i);
      //    cout<<1<<endl;
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            ll ret=INF;
            int sz=cir[i].size();
            g[0][1]=dp[cir[i][0]][1];
            g[0][0]=dp[cir[i][0]][0];
            for(int j=1;j<sz;j++)
            {
                g[j][1]=g[j-1][0]+dp[cir[i][j]][1];
                g[j][0]=min(g[j-1][1]+sum[cir[i][j]],g[j-1][0]+dp[cir[i][j]][0]);
            }
            ret=min(ret,g[sz-1][0]);
            g[0][1]=dp[cir[i][0]][1];
            g[0][0]=sum[cir[i][0]];
            for(int j=1;j<sz;j++)
            {
                g[j][1]=g[j-1][0]+dp[cir[i][j]][1];
                g[j][0]=min(g[j-1][1]+sum[cir[i][j]],g[j-1][0]+dp[cir[i][j]][0]);
            }
            ret=min(ret,g[sz-1][1]);
            ans+=ret;
        }
        cout<<ans<<endl;
    
        
   }
 return 0;
  }

