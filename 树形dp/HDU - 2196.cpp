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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int maxn=1e4+100;
typedef pair<int,ll> P;
vector<P>edge[maxn];
ll dp[maxn][3];
void init(int n)
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
     mem(dp,0);
    // ans=0;
}
void dfs(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].first;
        ll w=edge[u][i].second;
        if(v==pre) continue;
        dfs(v,u);
        if(dp[u][0]<dp[v][0]+w)
          {
              dp[u][1]=dp[u][0];
              dp[u][0]=dp[v][0]+w;
          }
        else if(dp[u][1]<dp[v][0]+w)
          dp[u][1]=dp[v][0]+w;
        //dp[u][0]=max(dp[u][0],dp[v][0]+1);
    }
}
void dfs2(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].first;
        ll w=edge[u][i].second;
        if(v==pre) continue;
        dp[v][2]=max(dp[u][2],(dp[u][0]==dp[v][0]+w?dp[u][1]:dp[u][0]))+w;
        //cout<<u<<" "<<dp[u][2]<<endl;
        dfs2(v,u);
    }
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       init(n);
       for(int i=2;i<=n;i++)
       {
           int u;ll w;
           cin>>u>>w;
          // cout<<u<<v;
           edge[i].pb(mpr(u,w));
           edge[u].pb(mpr(i,w));
       }
       dfs(1,0);
       dfs2(1,0);
      for(int i=1;i<=n;i++)
       cout<<max(dp[i][2],dp[i][0])<<endl
    
   }
 return 0;
  }

