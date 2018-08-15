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
const ll mod=19260817;
const int maxn=5e4+100;
ll dp[maxn];
int a[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(scanf("%d%d",&n,&m)==2)
   {
       for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
      //  sort(a+1,a+1+n);
        ll ans=0;
      //  a[0]=0;
       dp[0]=1;
     /*   for(int i=1;i<=m;i++)
        {
            dp[i]=0;
            for(int j=0;a[j]<=i&&j<=n;j++)
              dp[i]=(dp[i]+dp[i-a[j]])%mod;
          ans=(ans+dp[i])%mod;
          cout<<dp[i]<<endl;
        }
       */
      for(int i=1;i<=n;i++)
       for(int j=a[i];j<=m;j++)
       {
           dp[j]+=dp[j-a[i]];
       } 
      for(int i=1;i<=m;i++)
          ans+=dp[i],cout<<i<<": "<<dp[i]<<endl;
        printf("%lld\n",ans);
   }
 return 0;
  }
