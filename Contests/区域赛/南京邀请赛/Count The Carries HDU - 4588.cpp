#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll jisuan(ll x){
  ll ans=0;ll res=1;
  for(int i=1;res<=x;i++){
    res*=2;
    ans+=(x+1)/res*(res/2);
    if((x+1)%res>res/2) ans+=(x+1)%res-res/2;

  }
  return ans;
}
ll jisuan2(ll x){
    ll cnt=0;
 while(x){
   if(x&1) cnt++;
   x>>=1;
}
return cnt;}

int main(){
 ll a,b;
 //cout<<jisuan(3)<<endl;
 while(scanf("%lld%lld",&a,&b)==2){
    ll sum=jisuan2((a+b)*(b-a+1)/2);
    //cout<<sum<<endl;
    ll cnt=0;
    cnt=jisuan(b)-jisuan(a-1);
   // cout<<cnt<<endl;
   cout<<cnt-sum<<endl;
 }
return 0;
}
