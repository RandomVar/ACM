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
ll inv(ll a,ll mod) {
    return quickmod(a,mod-2,mod);
   }
int main(){
  int t;
  cin>>t;
  while(t--){
    ll n,m,k,p;
    cin>>n>>m>>k>>p;
    ll ans=0;
    if(k%2==0){
            ll ansn=1;
           ll ansm=quickmod(m,k/2,p);
        for(int i=0;i<=k;i+=2){
            ans=(ans+(ansn*ansm)%p)%p;
            ansn=(ansn*(n*n)%p)%p;
            ansm=(ansm*inv(m,p))%p;
        }
        cout<<ans<<endl;

    }
    else{
           ll ansn=n;
           ll ansm=quickmod(m,k/2-1,p);
        for(int i=1;i<=k;i+=2){
            ans=ans+ansn*ansm;
            ansn=(ansn*n*n)%p;
            ansm=(ansm*inv(m,p))%p;
        }
        cout<<ans<<endl;
    }
  }

}
