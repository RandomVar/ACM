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
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
ll dp[]
void dfs(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==pre) continue;
        dfs(v,u);
        for(int j=2;j<=k;k++)
        dp[k][u]+=dp[k-1][v]+1;
       dp[1][u]=0;
    }
    for(int i=0;i<edge[u].size();i++)
      for(int j=0;j<edge[u].size();j++)
      {
          if(i==j) continue;
          for(int x=1;x<k;x++)
            for(int y=1;y+x<k;y++)
              dp[y+x+1][u]+=dp[y][i]+dp[x][j]+2;
      }

    }

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,k;
   while(scanf("%d%d",&n,&k)==2)
   {
       mem(dp,0);
       for(int i=1;i<n;i++)
       {
           scanf("%d%d",&u,&v);
           edge[u].pb(v);
           edge[v].pb(u);
       }
       dfs(1,0);
       ll ans=0;
       for(int i=1;i<=n;i++)
        ans+=dp[k][i];
        cout<<ans<<endl;
   }


 return 0;
  }