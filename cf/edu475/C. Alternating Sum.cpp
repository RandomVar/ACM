#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+9;

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
ll  inv(ll a,ll mod) {
    return quickmod(a,mod-2);
   }
int main(){
  ll n,a,b,k;
  string s;
  while(cin>>n>>a>>b>>k){
    cin>>s;
    ll ans=0;
    for(int i=0;i<k;i++){
        ll c=(quickmod(a,n-i)*quickmod(b,i))%mod;
        if(s[i]=='+') ans=(ans+c%mod)%mod;
        else ans=(ans-c+mod)%mod;
    }

    ll ina=inv(a,mod);
    ll q=(quickmod(ina,k)*quickmod(b,k))%mod;
    ll s=(n+1)/k;
    if(q==1) cout<<(s*ans)%mod<<endl;
    else {
    ll daan=(ans*(quickmod(q,(n+1)/k)-1)%mod+mod)%mod;

    ll x=(inv(q-1,mod)+mod)%mod;
    daan=(daan*x+mod)%mod;
    cout<<daan<<endl;
  }}
return 0;
}
