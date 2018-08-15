#include<bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
using namespace std;
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
   int t;
   cin>>t;
   while(t--){
      ll n,k;
      cin>>n>>k;
      ll ans=0;
      for(int i=1;i<=n;i++){
        ans=(ans+quickmod(i,k))%mod;
      }
      cout<<ans<<endl;

   }
}
