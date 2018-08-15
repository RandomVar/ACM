#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[1010];
int main(){
  ll n,w;
  while(cin>>n>>w){
        sum[0]=0;
    for(ll i=1;i<=n;i++){
        ll t;
        cin>>t;
        sum[i]=sum[i-1]+t;
    }
    ll low=0;ll high=w;
  for(ll i=1;i<=n;i++){
    low=max(low,-sum[i]);
    high=min(high,w-sum[i]);
  }
  if(low>high) cout<<0<<endl;
  else cout<<(high-low+1)<<endl;
  }

}
