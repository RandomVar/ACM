#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod=9973;
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

int main()
{
    ll n,a;
    int t;
    cin>>t;
    while(t--)
    {
       cin>>n>>a;
       // a%=mod;
       ll x=quickmod(a,mod-2);
        cout<<n*x%mod<<endl;
    }
    return 0;
}