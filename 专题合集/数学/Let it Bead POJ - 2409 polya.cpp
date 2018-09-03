#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
ll gcd(ll a,ll b){
         if(a < b){
                   long long temp;
                   temp = a;
                   a = b;
                   b = temp;
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
                   r = a % b;
         }
         return b;
}
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
 ll n,m;
 while(cin>>m>>n&&n&&m){
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll t=gcd(n,i);
        ans+=quickmod(m,t);
    }
    if(n%2){
        ans+=n*quickmod(m,(n+1)/2);
    }
    else {
        ans+=n/2*quickmod(m,n/2);
        ans+=n/2*quickmod(m,(n+2)/2);
    }
    ans/=2*n;
    cout<<ans<<endl;
 }
}
