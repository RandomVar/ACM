#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=666666666;
const int maxn=1e5+100;
ll dp[maxn];

int main()
{
  int n;
  while(cin>>n)
  {
  
    dp[0]=1;
    dp[1]=1;
    ll sum=2;
   for(int i=2;i<=n;i++)
    {
      dp[i]=sum;sum=(sum+dp[i])%mod;
     // cout<<i<<" "<<dp[i]<<endl;
    }
   
   ll ans=0;
   for(int i=6;i<=n;i++)
    if(n-i>=0) ans=(ans+dp[n-i])%mod;
    cout<<ans<<endl;
  }
}