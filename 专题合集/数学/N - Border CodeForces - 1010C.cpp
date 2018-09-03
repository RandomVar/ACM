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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n,k;
    while(cin>>n>>k)
    {
        ll ans=k;
        for(ll i=1;i<=n;i++)
        {
            ll t;
            cin>>t;
            t%=k;
            if(t==0) t=k;
            ans=gcd(ans,t);
        }
          cout<<k/ans<<endl;
        if(k%ans==0) cout<<0<<" ";
        for(ll i=1;i*ans<k;i++)
          cout<<ans*i<<" ";
      
          cout<<endl;
    }
 return 0;
  }
