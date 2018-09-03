/***
总的个数用算术基本定理(a1+1)*(a2+1)*……*(as+1)/2

减去1-b个数 遍历一遍得

b*b>=a 一定不存在 从1e12降到1e6

注意不能是方形
***/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1000000;
int prime[MAXN+1];
void getPrime() {
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++) {
            if(!prime[i])
                prime[++prime[0]]=i;
    for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)  {
          prime[prime[j]*i]=1;
    if(i%prime[j]==0) break;
      } } }


ll getFactors(long long x) {

    ll ans=1;
    long long tmp=x;
    for(int i=1;i<prime[0]&&prime[i]<=tmp/prime[i];i++) {
        ll cnt=0;
        if(tmp%prime[i]==0){
            while(tmp%prime[i]==0){
            tmp/=prime[i];
            cnt++;
            }
            ans*=(cnt+1);
        } }
       if(tmp!=1)  {ans*=2;}
         return ans;
    }

int main(){
  int t;
  scanf("%d",&t);int k=0;
  getPrime();
  while(t--){
        ll a,b;
       scanf("%lld%lld",&a,&b);
       if(b*b>=a) printf("Case %d: 0\n",++k);
       else{
      ll ans=getFactors(a);

     ans=ans/2;
      for(ll i=1;i<b;i++)
        if(a%i==0) ans--;
        printf("Case %d: %lld\n",++k,ans);}

  }
return 0;
}
