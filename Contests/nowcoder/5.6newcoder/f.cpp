
/*
费用的数据范围 1e8
价值的数据范围 100
改变限制
dp[i][j] 前i个物品中挑选价值为j的最小费用
然后选出最小费用在限制之内的最大价值

*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e6;
int c[110];
int v[110];
int dp[110][110*110];
int main(){
  int t;
  cin>>t;
  while(t--){
        int n,m;
  cin>>n>>m;
        memset(dp,0x3f,sizeof(dp));
        int MAX=0;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>v[i];
        MAX=max(MAX,v[i]);}
    dp[1][0]=0;
    for(int i=1;i<=n;i++)
      for(int j=0;j<=n*MAX;j++){
         if(j<v[i]){
            dp[i+1][j]=dp[i][j];
         }
         else {
            dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+c[i]);
         }
    }
    int ans=0;
    for(int i=0;i<=n*MAX;i++)
        if(dp[n+1][i]<=m) ans=i;
    cout<<ans<<endl;
  }

return 0;
}
