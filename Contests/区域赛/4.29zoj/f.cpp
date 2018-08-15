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
const ll mod=1e9;
const int maxn=6*1e5+10;
ll a[maxn];
ll p[maxn];
ll sum[40][maxn];
ll pow_m(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
		if(res>2*1e9+1e7) return -1;
	}
	return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  int n,m;
  while(t--){
        cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>p[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=31;i++){
            sum[i][0]=0;
        for(int j=1;j<=n;j++)
            sum[i][j]=(sum[i][j-1]+a[j]/i)%mod;
    }
    ll cnt=0;
    for(int i=1;i<=m;i++){
        ll ans=0;
        for(int j=1;j<=31;j++){
            ll r=pow_m(p[i],j);
            ll l=pow_m(p[i],j-1);
            if(l==-1) break;
            int p1=upper_bound(a+1,a+n+1,r)-a;//>
            int p2=upper_bound(a+1,a+n+1,l)-a;//>
            //if(p1==n+1) p1=n;
            if(p2==n+1) break;
           ans=(ans+sum[j][p1-1]-sum[j][p2-1])%mod;
        }
    cnt=(cnt+(ans*i)%mod)%mod;
    }
  cout<<cnt<<endl;
  }
return 0;
}
