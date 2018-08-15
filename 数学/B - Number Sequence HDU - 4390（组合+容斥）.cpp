#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
map<ll,ll>mp;
ll c[50][50];
void getFactors(long long x) {

    long long tmp=x;
    for(int i=2;i<=tmp/i;i++) {
        if(tmp%i==0){
            while(tmp%i==0){
              mp[i]++;
            tmp/=i;
            }
        } }
       if(tmp!=1)  {
         mp[tmp]++;
         }

    }
void init(){
    for(int j=0;j<50;j++)
        c[0][j]=1;
  for(int i=1;i<50;i++)
    for(int j=0;j<50;j++)
  {
     if(i==j) c[i][j]=1;
     else if(j<i) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i][j-1])%mod;
     // cout<<j<<" "<<i<<" "<<c[i][j]<<endl;
  }


}
int main(){
   init();
   int n;
    while(scanf("%d",&n)==1){
            mp.clear();
        for(int i=1;i<=n;i++){
            ll t;
          scanf("%lld",&t);
         getFactors(t);
        }
        ll ans=0;
        map<ll,ll>::iterator it;
       for(int i=1;i<=n;i++){
            ll cnt=c[i-1][n];
        for(it=mp.begin();it!=mp.end();it++){
            ll x=it->second;
            cnt=(cnt*c[n-i][x+n-i])%mod;
        }
        if(i%2)  ans=(ans+cnt)%mod;
        else ans=(ans-cnt+mod)%mod;
    }
    printf("%lld\n",ans);
    }
return 0;
}
