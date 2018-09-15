#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
ll dp[2][10005];
map<ll,ll>mp;
map<ll,ll>::iterator it;
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
   #endif
  int t;scanf("%d",&t);
  while(t--)
  {
    mp.clear();
    int n,q; scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;i++)
    {
      ll v,c;
      scanf("%lld%lld",&v,&c);
      for(int i = 0;i<c;i++)
      {
        ll ans = v*(1LL<<i);
        if(ans > 10000) break;
        mp[ans]++;
      }
    }
    clr(dp,0);
    int now = 0;
    int ne;
    for(it = mp.begin();it!=mp.end();it++)
    {
      ne = now^1;
      (dp[ne][it->first] += it->second)%=mod;
      for(int j = 10000;j>=it->first;j--)
      {
        (dp[ne][j] += dp[now][j-it->first])%=mod;
      }
      now ^= 1;
    }
  for(int i = 1;i<=q;i++)
  {
    int p;
    scanf("%d",&p);
    printf("%lld\n",dp[now][p]%mod);
  }
  }
  return 0;
}
