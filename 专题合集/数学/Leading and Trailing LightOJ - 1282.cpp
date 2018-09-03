#include<bits/stdc++.h>
#define ll long long
using namespace std;
int quickmod(ll a,ll b,ll mod){
  ll res=1;
  while(b){
    if(b&1) res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return (int)res;
}
int main(){
  int t;
  cin>>t;int tt=0;
  while(t--){
    ll n,k;
    cin>>n>>k;
    int last=quickmod(n,k,1000);//attention leading 0
    int w=k*log10(n);
    double x=pow(10.0,1.0*k*log10(n)-w);
    while(x<100) x*=10;
    int ans=x;
    printf("Case %d: %d %03d\n", ++tt, ans, last);
  }
return 0;
}
