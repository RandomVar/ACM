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
int dp[110][110];
int mp[110][110];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,k;
bool check(int i,int j){
   if(i<0||i>=n||j<0||j>=n) return 0;

  return 1;
}
int dfs(int u,int v){
  if(dp[u][v]!=-1) return dp[u][v];
      dp[u][v]=mp[u][v];
   for(int i=1;i<=k;i++)
     for(int j=0;j<4;j++){
        int xx=u+dx[j]*i;
        int yy=v+dy[j]*i;
        if(check(xx,yy)&&mp[xx][yy]>mp[u][v])
           dp[u][v]=max(dp[u][v],dfs(xx,yy)+mp[u][v]);

     }
     /*for(int j=0;j+i<=k;j++){
       if(i==0&&j==0) continue;
         if(check(u+i,v+j)&&mp[u+i][v+j]>mp[u][v]){
           dp[u][v]=max(dp[u][v],dfs(u+i,v+j)+mp[u][v]);
         }
         if(check(u+i,v-j)&&mp[u+i][v-j]>mp[u][v]){
              dp[u][v]=max(dp[u][v],dfs(u+i,v-j)+mp[u][v]);
         }
         if(check(u-i,v-j)&&mp[u-i][v-j]>mp[u][v]){
              dp[u][v]=max(dp[u][v],dfs(u-i,v-j)+mp[u][v]);
         }
         if(check(u-i,v+j)&&mp[u-i][v+j]>mp[u][v]){
              dp[u][v]=max(dp[u][v],dfs(u-i,v+j)+mp[u][v]);
         }
     }*/
     //cout<<dp[u][v]<<endl;
return dp[u][v];
}
int main(){
//  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  #ifndef ONLINE_JUDGE
      freopen("data.in", "r", stdin);
      freopen("data.out", "w", stdout);
  #endif
  //int n,k;
  while(scanf("%d%d",&n,&k)==2){
    if(n==-1&&k==-1) break;
      memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
            scanf("%d",&mp[i][j]);
         //cin>>mp[i][j];
     printf("%d\n",dfs(0,0));
      // cout<<dfs(0,0)<<endl;
  }

}
