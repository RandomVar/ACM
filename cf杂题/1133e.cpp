#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+100;
int a[maxn];
int dp[maxn][maxn];
int s[maxn];
int main()
{
  int n,k;
  while(cin>>n>>k)
  {
    for(int i=1;i<=n;i++)
     cin>>a[i];
     sort(a+1,a+1+n);
     memset(dp,0,sizeof(dp));
   s[1]=1;
   for(int i=2;i<=n;i++)
   {
     if(a[i]-a[s[i-1]]<=5) s[i]=s[i-1];
     else
     {
       s[i]=s[i-1];
       while(a[i]-a[s[i]]>5)
       {
           s[i]++;
       }
     }
   }
  for(int e=1;e<=k;e++)
    for(int i=1;i<=n;i++)
    {
      // cout<<"!!"<<endl;
      int cnt=0;
      dp[i][e]=max(dp[i][e-1],dp[i-1][e]);
    
      dp[i][e]=max(dp[i][e],dp[s[i]-1][e-1]+i-s[i]+1);
    //  cout<<e<<" "<<i<<" "<<dp[i][e]<<" "<<j<<" "<<dp[j][e-1]<<" "<<cnt<<endl;
    }
    
   cout<<dp[n][k]<<endl;
   }
}