#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
ll cal(ll v){
    ll ans=1;
  for(int i=1;;i++)
  {
      ans*=2;
      if(ans>v) return ans/2;
  }


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
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
  scanf("%d",&t);
  while(t--){
    ll a,b,v;
    scanf("%lld%lld%lld",&a,&b,&v);
   /* ll x=v;
    int i=0;
    while(x){
        if(x==1) i++;
        else break;
        x/=2;
    }
    cout<<max(quickmod(2,i),b-a+1)<<endl;
    */
    ll t=cal(v);
    ll l=max(a,t);
    ll r=min(b,v);
    ll l2=max((ll)0,a);
    ll r2=min(b,t-1);
    if(l<=r2+1)
        printf("%lld\n",r-l2+1);
        //cout<<r-l2+1<<endl;
    else
      printf("%lld\n",max(r-l+1,r2-l2+1));
    //cout<<max(r-l+1,r2-l2+1)<<endl;

  }


  }

