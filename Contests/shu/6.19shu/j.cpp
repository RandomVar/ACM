#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
const int mod=1e9+7;
ll dp[maxn];
ll a[maxn];
int main(){
   int t;
   scanf("%d",&t);
   //cin>>t;
   while(t--){
     int n;
     scanf("%d",&n);
     //cin>>n;
     for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
        //cin>>a[i];
     dp[1]=a[1];
     for(int i=2;i<=n;i++){
         dp[i]=((dp[i-1]*a[i])%mod+(dp[i-1]+a[i])%mod)%mod;

     }
     printf("%lld\n",dp[n]);
     //cout<<dp[1]<<endl;
     //cout<<dp[n]<<endl;
   }

return 0;
}
