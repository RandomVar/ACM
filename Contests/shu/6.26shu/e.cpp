#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
const int mod=1e9+7;
ll eular(ll n) {
    ll ans = n;
    for(ll i = 2;i*i <= n;i++) {
        if(n % i == 0)  {
          ans -= ans/i;
          while(n % i == 0)
            n /= i; } }
       if(n > 1)ans -= ans/n;
    return ans;
     }
int main(){
 // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n,k;
  while(scanf("%lld%lld",&n,&k)==2){

    for(int i=0;i<(k+1)/2;i++){
       n=eular(n);
       if(n<2) {n=1;break;}
    }
    printf("%lld\n",n%mod);
    //cout<<n%mod<<endl;

  }
return 0;
}
