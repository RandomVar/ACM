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
const ll base=998244353;
const ll mod=1e9+7;

map<ll,ll>mp;
ll a[4010];
ll h[4010];
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

ll inv(ll a) {
    return quickmod(a,mod-2);
   }
void init()
{
  h[1]=base;
  for(int i=2;i<=4000;i++)
    h[i]=(h[i-1]*base)%mod;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  init();
  while(t--)
  {
      int n;
      cin>>n;
      for(int i=1;i<=n;i++)
      {
          ll u,v;
          cin>>u>>v;
          if(v<u) swap(u,v);
          a[i]=(h[u]+v)%mod;
      }
      ll ans=0;
      for(int i=1;i<n;i++){
          mp.clear();
          ll cnt=1;
          for(int k=1;k<=i;k++)
            {
               cnt=(cnt*a[k])%mod;
            }
            mp[cnt]++;
        for(int j=i+1;j<=n;j++)
        {
             cnt=(cnt*inv(a[j-i]))%mod;
             cnt=(cnt*a[j])%mod;
             //bh[a[j-i]]--;
            // if(bh[a[j-i]]==0) bh.erase(a[j-i]);
             //bh[a[j]]++;
             mp[cnt]++;
        }
        map<ll,ll>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
           if(it->second>1){
               ans+=(it->second)*(it->second-1)/2;
           }
        }
      }
      cout<<ans<<endl;
  }

return 0;
  }

