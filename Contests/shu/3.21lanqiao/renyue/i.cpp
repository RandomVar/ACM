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
     dp[i][i][1]=1;
  for(int j=2;j<=k;j++)
    for(int i=1;i<=n;i++)
      for(int c=1;c<=n;c++)
      {
        if(i+c>n) break;
       for(int p=1;p<=c;p++)
      {
         dp[i+c][c][j]+=dp[i][p][j-1];
      }
      }
      ll ans=0;
      for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
       ans+=dp[n][i][j];
    cout<<ans<<endl;
  }
}