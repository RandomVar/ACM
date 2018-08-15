#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
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
   ll x,k;
   while(cin>>x>>k){
      if(x==0){
        cout<<0<<endl;
        continue;
      }
      x%=mod;
      ll q=quickmod(2,k+1)%mod;
      ll p=quickmod(2,k)%mod;
      cout<<(((x*q)%mod+1)%mod-p+mod)%mod<<endl;
   }
return 0;

}
