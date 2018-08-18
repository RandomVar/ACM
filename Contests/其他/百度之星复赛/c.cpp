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
const ll mod=1e9+7;
const int maxn= 1e5+100;
int p[maxn];
ll dp[40];
vector<ll>vec[maxn];
ll val[maxn];
ll ko[maxn];
void init(int n)
{
    for(int i=0; i<=n; i++)
        p[i]=i;
}
int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}

int Union(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)
        return 0;
      p[x1]=y1;
      return 1;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   ko[0]=1;
   for(int i = 1;i<=30;i++) ko[i] = ko[i-1]*2%mod;
   while(t--)
   {
       int n,m;
       scanf("%d%d",&n,&m);
       init(n);
       for(int i=0;i<=n;i++)
        vec[i].clear();

       for(int i=1;i<=n;i++)
        scanf("%lld",&val[i]);
       for(int i=1;i<=m;i++)
       {
           int u,v;
           scanf("%d%d",&u,&v);
           Union(u,v);
       }
       for(int i=1;i<=n;i++)
       {
           vec[Find(i)].pb(val[i]);
       }
        
        for(int i=1;i<=n;i++)
        {
            if(!vec[i].empty())
              sort(vec[i].begin(),vec[i].end());
        }
        ll ans=0;
         for(int i = 1;i<=n;i++)
        {
          int len = vec[i].size();
         mem(dp,0);
        for(int j = 0;j<len;j++)
        {
        for(int k = 0;k<30;k++)
        {
          if(vec[i][j] & (1<<k))
          {
            ans = (ans+(vec[i][j]*dp[k]%mod)*ko[k])%mod;
            dp[k]++;
          }
        }
      }
    }
      printf("%lld\n",ans);

     


   }
 return 0;
  }

