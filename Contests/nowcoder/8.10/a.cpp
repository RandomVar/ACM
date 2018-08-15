#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const ll mod=1e9+7;
ll dp[1100][1100];
ll a[3];
int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(scanf("%d%d",&n,&m)==2)
   {
       mem(dp,0);
       for(int j=1;j<=m;j++)
         dp[1][j]=1;
         a[1&1]=m%mod;
       for(int i=2;i<=n;i++)
       {
           a[i&1]=0;
         for(int j=1;j<=m;j++)
         {
            
             dp[i][j]=(dp[i][j]+a[(i+1)&1]-dp[i-1][j]+mod)%mod;
              a[i&1]=(a[i&1]+dp[i][j])%mod;
         }
       }
       printf("%lld\n",a[n&1]);
   }
 return 0;
  }

