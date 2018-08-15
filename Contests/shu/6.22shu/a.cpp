#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=50010;
ll dp[maxn][510];
ll ans[maxn];
int k;
vector<int>edge[maxn];
void dfs1(int u,int pre){
    dp[u][1]=1;
  for(int i=0;i<edge[u].size();i++){
      int t=edge[u][i];
      if(t==pre) continue;
      dfs1(t,u);
      for(int j=2;j<=k+1;j++)
        dp[u][j]+=dp[t][j-1];

  }
}
ll cnt;
void dfs2(int u,int pre){
    for(int i=0;i<edge[u].size();i++){
         int t1=edge[u][i];
         if(t1==pre) continue;


         for(int j=1;j<k;j++){
             ans[u]+=dp[t1][j]*(dp[u][k-j+1]-dp[t1][k-j]);
         }



      dfs2(t1,u);
}
  ans[u]/=2;
  ans[u]+=dp[u][k+1];
//cout<<u<<" "<<ans[u]<<endl;
  cnt+=ans[u];
}

int main(){
   int n;
   while(scanf("%d%d",&n,&k)==2){
        for(int i=0;i<=n;i++)
        edge[i].clear();
   memset(dp,0,sizeof(dp));
   memset(ans,0,sizeof(ans));
      for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        //cin>>u>>v;
        edge[u].pb(v);
        edge[v].pb(u);
      }
      cnt=0;
      dfs1(1,0);
      dfs2(1,0);
      printf("%lld\n",cnt);
      //cout<<cnt<<endl;
   }
   return 0;
}
