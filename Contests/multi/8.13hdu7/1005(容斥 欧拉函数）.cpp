/*
HDU6390
公式推导：
对每个质因子p算贡献
a=p^(x1),b=p^(x2) 
若 x1!=0&&x2!=0
   phi(ab)=(p-1)*p^(x1+x2-1)
   phi(a)phi(b)=(p-1)^2*p^(x1+x2-2)
   phi(ab)/(phi(a)*phi(b))=p/p-1
若 x1=0
  phi(ab)=(p-1)*p^(x2-1)
  phi(a)phi(b)=(p-1)*p^(x2-1)
  phi(ab)/(phi(b)*phi(b))=1
得 G(a,b)=phi(ab)/(phi(a)*phi(b))=d/phi(d) d=gcd(a,b)

设 f[d]为d|(a,b)的对数
   g[d]为d=(a,b)的对数
则 f[d]=(n/d)*(m/d)
   g[d]=f[d]-sum(g[i*d]) i>=2
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
const int maxn=1e6+10;
int euler[maxn];
ll f[maxn];
ll inv[maxn];
ll mod;
void getEuler() {
    memset(euler,0,sizeof(euler));
    euler[1] = 1;
    for(int i = 2;i < maxn;i++)
        if(!euler[i])
          for(int j = i;j < maxn; j += i){
            if(!euler[j])
              euler[j] = j;
            euler[j] = euler[j]/i*(i-1);
           }
 }
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
int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   //cin>>t;
   getEuler();
   while(t--)
   {
       ll n,m;
      scanf("%lld%lld%lld",&n,&m,&mod);
       //cin>>n>>m>>mod;
       int cc=max(n,n);
       for(int i=1;i<=cc;i++)
         f[i]=(n/i)*(m/i);
        for(int i=cc;i>=1;i--)
        {
          for(int j=2;j*i<=cc;j++)
            f[i]-=f[j*i];
          f[i]%=mod;
        //  cout<<i<<" "<<f[i]<<endl;
        }
            inv[1]=1;
         for(int i=2;i<=cc;i++)
            inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        ll ans=0;
        for(int i=1;i<=cc;i++)
         {
             ans=(ans+f[i]*i%mod*inv[euler[i]]%mod)%mod;
         }
         printf("%lld\n",ans);
         //cout<<ans<<endl;
   }
 return 0;
  }
