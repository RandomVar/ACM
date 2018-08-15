#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 map<ll,ll>mp;
 ll x;
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
ll a[20][10];
void dfs(ll ans,int i,int nn){
   if(i==nn+1)
   {
      mp[ans]++;return;
   }
   for(int j=1;j<=6;j++){
       dfs((ans*a[i][j])%mod,i+1,nn);
   }
}
ll dfs2(ll ans,int i,int nn){
   if(i==nn+1)
   {
      ll c=inv(ans);
       c=(x*c)%mod;
       //cout<<c<<" "<<mp[c]<<endl;
      return mp[c];
   }
   ll cnt=0;
   for(int j=1;j<=6;j++){
       cnt=cnt+dfs2((ans*a[i][j])%mod,i+1,nn);
   }
   return cnt;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
     mp.clear();
     int n;
     scanf("%d%lld",&n,&x);
     for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++)
             scanf("%lld",&a[i][j]);
     }
    dfs(1,1,n/2);
    ll cnt=0;
     printf("%lld\n",dfs2(1,n/2+1,n));

  }
return 0;
}

