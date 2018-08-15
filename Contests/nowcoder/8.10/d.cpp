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
const int maxn=50010;
vector< pair<int,int> >edge[maxn];
ll f[maxn];
int d[maxn];
void dfs(int u)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        dfs(v);
        f[u]=max(f[u],f[v]+edge[u][i].sec);
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++)
     {
         edge[i].clear();
         d[i]=f[i]=0;
     }
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(scanf("%d",&n)==1)
  {
      init(n);
      for(int i=1;i<n;i++)
      {
          int u,v,c;
          scanf("%d%d%d",&u,&v,&c);
          edge[v].push_back(mpr(u,c));
          d[u]++;
      }
      int rt;
      for(int i=1;i<=n;i++)
        if(d[i]==0) {rt=i;break;}
     dfs(rt);
     printf("%lld\n",f[rt]);
  }
 return 0;
  }
