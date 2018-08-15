#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e6+100;
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
ll a[maxn];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n)
  {
      ll ans=0;
      for(int i=1;i<=n;i++)
        cin>>a[i];
     for(int i=1;i<n;i++)
     {
         ans=(ans+((a[i]*(ll)(n-i+2))%mod*quickmod(2,n-i-1))%mod)%mod;
        // ans=(ans+(a[i]*((n-i+2)*quickmod(2,n-i-1))%mod)%mod)%mod;
     }
     ans=(ans+a[n])%mod;
   cout<<ans<<endl;
  }


return 0;
  }

