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
const int maxn=1100;
ll a[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1)
   {
       for(int i=1;i<=n;i++)
         scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        ll ans=-1;
        for(int i=1;i<=n-2;i++)
        {
            if(a[i+2]<a[i+1]+a[i])
                ans=max(ans,a[i]+a[i+1]+a[i+2]);
        }
        printf("%lld\n",ans);
   }
 return 0;
  }

