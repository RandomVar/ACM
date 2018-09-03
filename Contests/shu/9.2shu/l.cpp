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
const int maxn=1e5+100;
vector<int>edge[maxn];
int ans;
void dfs(int u,int pre,int dep)
{
    for(int i=0;i<edge[u].size();i++)
      {
          int v=edge[u][i];
          if(v==pre) continue;
          dfs(v,u,dep+1);
          ans=max(ans,dep+1);
      }
}
void init(int n)
{
  for(int i=0;i<=n;i++)
   edge[i].clear();
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,a;
   while(scanf("%d%d",&n,&a)==2)
   {
       init(n);
       for(int i=1;i<n;i++)
       {
           int u,v;
           scanf("%d%d",&u,&v);
           edge[u].pb(v);
           edge[v].pb(u);
       }
       dfs(a,0,0);
      printf("%d\n",ans+1);
   }
 return 0;
  }
