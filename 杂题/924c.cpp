#include<bits/stdc++.h>
#define  ll long long
using namespace std;
const int maxn=1e5;
ll a[maxn+10];
ll t[maxn+10];
int main(){
  ll n;
  while(cin>>n){
   ll cnt=0;int pre=0;
   for(int i=0;i<n;i++){
    cin>>a[i];cnt+=a[i];
   }
   ll cur=-1;
   for(int i=n-1;i>=0;i--){
    t[i]=max(cur-1,(ll)0);
    t[i]=max(cur-1,a[i]);
    if(t[i]<0) t[i]=0;
    cur=t[i];}
    ll ans=0;
    //cur=0;
    for(int i=0;i<n;i++){
       cur=max(cur,t[i]);
       ans+=cur;
    }
    //cout<<ans<<endl;
    cout<<ans-cnt<<endl;
  }
return 0;
}
