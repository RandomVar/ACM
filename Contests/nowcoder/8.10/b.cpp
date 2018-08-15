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
const int maxn=1000010;
ll sz[maxn];
vector<int>edge[maxn];
void dfs(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v]+1;
      
    }
}
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
     edge[i].clear();
     sz[i]=0;
    }
     //mem(sz,0);
     //mem(ans,0);
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1)
   {
       init(n);
       for(int i=1;i<n;i++)
       {
           int u,v;
           scanf("%d%d",&u,&v);
           edge[u].pb(v);
           edge[v].pb(u);
       }
       dfs(1,0);
       ll ans=0;
       for(int i=0;i<edge[1].size();i++)
       {
           int v=edge[1][i];
         ans=max(ans,sz[v]+1);
       }
       printf("%lld\n",ans);
   }
 return 0;
  }

