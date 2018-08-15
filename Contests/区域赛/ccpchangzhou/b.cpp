
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
const ll mod=998244353;
ll p[30];
ll q[30];
ll cc[30];
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

ll ans=0;int m;
void dfs(int i,ll shujv){
  if(i==m) return;
  dfs(i+1,shujv);
  shujv=(shujv*cc[i])%mod;
//  if(flag) shujv=(shujv*e)%mod;
//  cout<<shujv<<endl;
  ans=(ans+shujv)%mod;
  dfs(i+1,shujv);
}

int main(){
//    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  while(t--){
   // int m;
    scanf("%d",&m);
    ll n=1;
    //ll ans=1;
    ll x=1;ll y=1;
     for(int i=0;i<m;i++){
        scanf("%lld%lld",&p[i],&q[i]);
        n=(n*quickmod(p[i],q[i]))%mod;
        cc[i]=(((p[i]-1)*inv(p[i]))%mod*q[i])%mod;
//        cout<<cc[i]<<endl;
     }
//     e=inv(n);
     ans=0;
//     dfs(0,1);
//     ans=(ans*n+n)%mod;
//     ans=(ans+)%mod;
   for(int i=0;i<m;i++){
      ans=(ans+(ans+1)*cc[i])%mod;
   }
   ans=((ans+1)*n)%mod;
     printf("%lld\n",ans);
//    cout<<ans<<endl;
  }
  return 0;
}
