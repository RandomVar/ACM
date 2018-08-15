#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+100;
const ll mod=1000000007;
ll dp[maxn];
ll inv[maxn];
void init()
{
     inv[1]=1;
   for(int i=2;i<=1e6+10;i++)
      inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    dp[1]=1;
  for(int i=2;i<=1e6;i++)
  {
      dp[i]=(dp[i-1]*(4*i-2))%mod*inv[i+1]%mod;
  }
}

int main()
{
    int n;
    init();
    int t;
    cin>>t;int cas=0;
    while(t--)
    {
        cin>>n;
        cout<<"Case #"<<++cas<<":"<<endl;
     cout<<dp[n]<<endl;
     }
}