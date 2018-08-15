#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod= 998244353;
int a[100010];
ll jiecheng(int n){
  ll ans=1;
  for(int i=2;i<=n;i++)
    ans=(ans*i)%mod;
return ans;
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
ll inv(ll a) {
    return quickmod(a,mod-2);
   }

int main(){
   int t;
//   cin>>t;
   scanf("%d",&t);
   while(t--){
    int n;
//    cin>>n;
  scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
//        cin>>a[i];
    sort(a,a+n);
    ll x=jiecheng(n-2);
    ll ans=0;
    /*int c[10000];
    for(int j=n-1;j>=0;j--){
        c[j]=c[j+1]/(n-1)+a[j]*x*(n-1);
        cout<<c[j]<<endl;}
    for(int j=0;j<n;j++)
        ans+=c[j];*/
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(i==0) ans=(ans+(a[j]*(x*(n-1))%mod))%mod;
            else ans=(ans+(a[j]*x)%mod)%mod;
        ans=(ans+a[i]*(x*(n-1)))%mod;
    }
        cout<<ans<<endl;
    x=((x*n)%mod*(n-1))%mod;
    ans=(ans*inv((x)%mod))%mod;
     printf("%lld\n",ans);
   }

}
