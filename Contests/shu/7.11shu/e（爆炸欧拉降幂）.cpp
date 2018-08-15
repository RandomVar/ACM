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
ll quickmod(ll a,ll b,ll c){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%c;
		a=a*a%c;
		b>>=1;
	}
	return res;
}
ll eular(ll n) {
    ll ans = n;
    for(ll i = 2;i*i <= n;i++) {
        if(n % i == 0)  {
          ans -= ans/i;
          while(n % i == 0)
            n /= i; } 
            }
       if(n > 1)ans -= ans/n;
    return ans;
     }
ll dfs(ll n, ll m)
{
    ll op = eular(m);
    if(n == 1) return n%m;
    if(n == 2) return n%m;
    if(n == 3) return 9%m;
   if(n == 4) return (1LL<<18)%m;
    if(m == 1) return 0;
        //cout<<quick(n,op,m)<<" "<<n<<endl;
    return quickmod(n,dfs(n-1,op)%op+op,m)%m;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n,m;
   while(cin>>n>>m){
      
        cout<<dfs(n,m)<<endl;

   }
  }

