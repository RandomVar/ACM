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
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
/*const int maxn=1e8+10;
ll f[maxn];
ll sum[maxn];
int k;
void init(){
  ll pre1=1;ll pre2=2;
   k=0;
  f[++k]=2;
  sum[k]=2;
 for(int i=3;i<maxn-1000;i++){
     ll x=pre1+pre2;
     pre1=pre2;
     pre2=x;
     if(i%3==2)
     {
         f[++k]=pre2;
         sum[k]=f[k]+sum[k-1];
         if(sum[k]>=(4*1e16)) break;
 }
 }
 cout<<k<<" "<<f[k]<<endl;
}*/
int main(){
   int t;
//init();
   scanf("%d",&t);
   while(t--){
      ll n;
      scanf("%lld",&n);
      if(n<34) {printf("10\n");continue;}
    ll ans=0;
      ll pre1=2;ll pre2=8;ll cnt=10;
      while(ans<n){
        ans=pre1+4*pre2;
        if(ans>n) break;
        pre1=pre2;
        pre2=ans;
        cnt+=ans;
      }

      printf("%lld\n",cnt);

   }
}
