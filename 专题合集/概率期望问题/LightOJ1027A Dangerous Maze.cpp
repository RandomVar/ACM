#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
ll quickmod(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
     if(b&1)
       res=res*a;
      a=a*a;
      b>>=1;
    }
    return res;
}
const int maxn=200;
ll a[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;int cas=0;
  scanf("%d",&t);
  while(t--)
  {
      int n;
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
       scanf("%lld",&a[i]);
    
    printf("Case %d: ",++cas);
     ll cnt=0;
     ll p2=0;ll p1=0;
     for(int i=1;i<=n;i++)
      if(a[i]>0) p1+=a[i],cnt++;
      else p2-=a[i];
   
    if(!cnt) 
       printf("inf\n");
    else 
    {
        ll q=cnt;
        ll p=p1+p2;
        ll x=gcd(p,q);
        p/=x;q/=x;
       printf("%lld/%lld\n",p,q);
    
    }
  }
 return 0;
  }

