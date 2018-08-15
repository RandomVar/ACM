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
const ll mod=1e9+7;
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
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll k;
  while(cin>>k)
  {
      ll res=1;
      for(int i=1;i<=k;i++)
      {
          ll t;
        cin>>t;
        t%=mod-1;
        res=(res*t)%(mod-1);
       }
       ll x=quickmod(2,res-1+mod-1);
       ll ans1=(x+(res%2==1?-1:1)+mod)%mod;
        ans1=ans1*quickmod(3,mod-2)%mod;
       cout<<ans1<<"/"<<x<<endl;
       
  }
 return 0;
  }

