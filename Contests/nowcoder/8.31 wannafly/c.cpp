/*
https://www.nowcoder.com/acm/contest/161/C
*/
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
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int mod=1e9+7;
const int maxn=5*1e5+100;
ll f[maxn];
ll g[maxn];
ll bai;
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
struct node{
  ll m,r,p;
  ll mv,rv,pv;
  void init()
  {
      r=r*bai%mod;
      p=p*bai%mod;
     rv=(1-r+mod)%mod;
     pv=(1-p+mod)%mod;
     mv=m*r%mod*p%mod;
  }  
}a[110];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m,l;
   bai=quickmod(100,mod-2);
   while(cin>>n>>l>>m)
   {
       mem(f,0);
       mem(g,0);
       int sum=0;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i].m>>a[i].r>>a[i].p;
           a[i].init();
         sum=sum+a[i].m;
       }
       f[0]=1;
      for(int i=1;i<=n;i++)
        {
         for(int s=sum;s>=a[i].m;s--)
         {
            f[s]=(f[s-a[i].m]*a[i].p%mod+f[s]*a[i].pv%mod)%mod;
            g[s]=(g[s-a[i].m]*a[i].p%mod+ f[s-a[i].m]*a[i].mv%mod + g[s]*a[i].pv%mod)%mod;
           
            // g[s]=(g[s-a[i].m]*a[i].mv%mod + g[s]*a[i].pv%mod)%mod;
            // g[s]=(g[s-a[i].m]*a[i].pv%mod*a[i].rv%mod+g[s]*(100-a[i].p)*bai%mod)%mod;
         }
         for(int s=a[i].m-1;s>=0;s--)
          {
              f[s]=f[s]*a[i].pv%mod;
              g[s]=g[s]*a[i].pv%mod;
          }
        }
        ll ans=0;
        for(int s=l;s<=sum;s++)
          ans=(ans+f[s]*m%mod-g[s]+mod)%mod;
        cout<<ans<<endl;
   }
 return 0;
  }
