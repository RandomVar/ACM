#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
const int maxn=1e6+100;
ll dp[maxn][5];
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
   #endif
   ll n,k;
   int t;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%lld%lld",&n,&k);
     ll pp=quickmod(2,k);
    dp[1][1]=pp;dp[1][0]=dp[1][2]=0;
     for(int i=2;i<=n;i++)
     {
       dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
       dp[i][2]=(dp[i-1][0]+dp[i-1][2])%mod;
       dp[i][0]=(dp[i-1][1]*(pp-2+mod)%mod+dp[i-1][2]*(pp-2+mod)%mod+dp[i-1][0]*(pp-3+mod)%mod)%mod;
     }
     ll ans=(dp[n][1]+dp[n][0])%mod;
     printf("%lld\n",ans);
   }

}
