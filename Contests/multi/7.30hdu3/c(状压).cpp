/*
给定一个n个点的无向图，m次加边或者删边操作。
在每次操作后统计有多少个匹配包含 k = 1,2,..., n/2条边。
n<=10,m<=3e4

加边 f[S]+=f[S−u−v]（s包含u,v)
减边 f[S]−=f[S−u−v]
*/
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
const int maxn=1<<12;
const ll mod=1e9+7;
ll dp[maxn];
ll ans[12];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        char c[2];
        mem(dp,0);
        dp[0]=1;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%s%d%d",c,&u,&v);
            u--;v--;
            if(c[0]=='+')
            {

                for(int s=(1<<n)-1;s>=0;s--)
                {
    
                    if((s&(1<<u))&&(s&(1<<v)))
                       dp[s]=(dp[s]+dp[s-(1<<u)-(1<<v)])%mod;
                }
            }
            else{
                for(int s=(1<<n)-1;s>=0;s--)
                {
                    if((s&(1<<u))&&(s&(1<<v)))
                       dp[s]=(dp[s]-dp[s-(1<<u)-(1<<v)]+mod)%mod;
                }
            }
              mem(ans,0);
        for(int s=(1<<n)-1;s>=0;s--)
        {
            int t=__builtin_popcount(s);
            t/=2;
            ans[t]=(ans[t]+dp[s])%mod;
        }
        for(int i=1;i<n/2;i++)
          printf("%lld ",ans[i]);
          printf("%lld\n",ans[n/2]);

    }
        }
      

 return 0;
  }

