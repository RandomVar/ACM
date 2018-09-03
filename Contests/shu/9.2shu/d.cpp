#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n;
  ll a,b,c,d;
  while(cin>>n>>a>>b>>c>>d)
  {
      if(c<a) swap(c,a);
      if(b<d) swap(b,d);
      ll x=(c-a)+(b-d);
    //   cout<<x<<endl;
    if(x>n) cout<<0<<endl;
    else
    {
        ll ans=(n-x)/2+1;
       if(x==0) ans--;
       cout<<ans<<endl;
     }
  }
 return 0;
  }
