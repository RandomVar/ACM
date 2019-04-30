#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=310;
ll dp[maxn][maxn][maxn];
int main()
{
  int n,k;
  while(cin>>n>>k)
  {
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
     dp[i][j][1]=1;
  for(int j=2;j<=k;j++)
  for(int c=1;c<=n;c++)
    for(int i=0;i<=n;i++)
      {
      if(i>=c)  dp[i][c][j]+=dp[i-c][c][j-1]+dp[i][c-1][j];
       else dp[i][c][j]+=dp[i][c-1][j];
        // dp[i][c][j]+=dp[i][c][j];
        // cout<<i+c<<" "<<c<<" "<<j<<" &"<<i<<" "<<c<<" "<<dp[i+c][c][j]<<endl;
      }/
      ll ans=0;
      for(int j=1;j<=k;j++)
       ans+=dp[n][n][j];
    cout<<ans<<endl;
  }
}