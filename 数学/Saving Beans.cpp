#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
ll fac[maxn];
void getf(ll p)
{
    fac[0]=1;
    for(int i=1;i<=p;i++)
        fac[i]=fac[i-1]*i%p;
}

ll quickmod(ll a,ll b,ll c){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%c;
		a=a*a%c;
		b>>=1;
	}
	return res;
}

ll lucas(ll n,ll m,ll p)
{
    ll ans=1;
    while(n&&m)
    {
        ll a=n%p;
        ll b=m%p;
        if(a<b) return 0;
        ans=(ans*fac[a]*quickmod(fac[b]*fac[a-b]%p,p-2,p))%p;
        n/=p;
        m/=p;
    }
    return ans;
}
int main()
{
    int t;
    ll  n,a,mod;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&a,&mod);
       getfac(mod);
        printf("%lld\n",lucas(n+a,n,mod));

    }
}