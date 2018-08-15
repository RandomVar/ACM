#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<stack>
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
const int maxn=1e6+100;
struct node{
 int t;ll cos;

};
vector<node>edge[maxn];
vector<node>g[maxn];
stack<int>st;
int low[maxn],dfn[maxn];
int instack[maxn];
int tot;
int scc;//强连通分量个数
int belong[maxn];//记录每个点属于哪个连通分量
int de[maxn];
ll co[maxn];
ll dp[maxn];
ll elo[maxn];
void init(){
 mem(dfn,0);
 mem(low,0);
 mem(instack,0);
 mem(de,0);
 mem(dp,0);
 mem(co,0);
 for(int i=0;i<maxn;i++)
   {
       edge[i].clear();
      g[i].clear();
   }

 while(!st.empty())
    st.pop();
   tot=scc=0;
   elo[1] = 0; elo[2] = 1;
   for (int i=3; i<=100000; ++i) elo[i] = elo[i-1] + (ll)i * (ll)(i - 1)/2;
}

ll cal(ll wartosc) {
	//x + x - 1 + x - 3 + x - 6 + x - 10 + ..
	ll x = 0, y = 1000000;
	while (x < y) {
		ll mid = (x + y) / 2 + 1;
		if (wartosc - mid * (mid - 1)/2 < 0) y = --mid;
		else x = mid;
	}
	return x * wartosc - elo[x];
}
/*
ll cal(ll val){
    ll pre=1;
    ll ans=0;
  for(ll i=0;i<val;i+=pre)
{
    ans+=val-i;
    pre+=i;
}
return ans;
}*/

ll dfs(int u){
    if(dp[u]) return dp[u];
  ll cnt=0;
  for(int i=0;i<g[u].size();i++){
     node e=g[u][i];
      cnt=max(cnt,dfs(e.t)+e.cos);
  }
  dp[u]=cnt+co[u];
  return dp[u];
}

void tar(int u){
  dfn[u]=low[u]=++tot;
  st.push(u);
  instack[u]=1;
  for(int i=0;i<edge[u].size();i++){
     node x=edge[u][i];
     int v=x.t;
     if(!dfn[v]){
        tar(v);
        if(low[u]>low[v])
            low[u]=low[v];
        }
     else if(instack[v]&&low[u]>dfn[v])
        low[u]=dfn[v];
        }
     if(low[u]==dfn[u]) {
        int v;
         scc++;
         do{
            v=st.top();
            st.pop();
            belong[v]=scc;
            instack[v]=0;
           }while(v!=u);
      }
     }
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(scanf("%d%d",&n,&m)==2){

        init();
      for(int i=0;i<m;i++){
         int u,v;ll w;
         scanf("%d%d%lld",&u,&v,&w);
         //cin>>u>>v>>w;
         edge[u].push_back(node{v,w});
      }
      int s;
      scanf("%d",&s);
      //cin>>s;
      tar(s);
      for(int i=1;i<=n;i++){
          for(int j=0;j<edge[i].size();j++){
            node e=edge[i][j];
        if(belong[i]!=belong[e.t]){
            g[belong[i]].push_back(node{belong[e.t],e.cos});
            de[belong[e.t]]++;
        }
         else  co[belong[i]]+=cal(e.cos);
           }
      }
     // for(int i=1;i<=scc;i++)
       // cout<<co[i]<<endl;
      //ll ans=0;
     ll ans=dfs(belong[s]);

      printf("%lld\n",ans);
  // cout<<ans<<endl;


   }
return 0;

}
