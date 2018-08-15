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
const int maxn=110000;
struct node{
  int t;ll val;
};
int n;
int fa[maxn][35];
int deep[maxn];
ll d[maxn];
int vis[maxn];
vector<node>edge[maxn];
int st,ed;
ll sum;
void init(){
  for(int i=0;i<maxn;i++)
    edge[i].clear();
    st=-1;
    mem(vis,0);
   mem(deep,0);
   mem(fa,0);
   mem(d,0);
}

void addedge(int u,int v,ll val){
//  e.pb(node{u,v,val});
  edge[u].push_back(node{v,val});
  edge[v].push_back(node{u,val});
}

void dfs(int u,int pre){
  if(st!=-1) return;
  vis[u]=1;
   for(int i=0;i<edge[u].size();i++){
        node t=edge[u][i];
       if(t.t==pre) continue;
       if(vis[t.t]){
           st=u;
           ed=t.t;
           sum=t.val;
           continue;
       }
      dfs(t.t,u);
   }
}
void dfs2(int u,int pre){

   for(int i=0;i<edge[u].size();i++){
        node t=edge[u][i];
       if(t.t==pre) continue;
       if(u==st&&t.t==ed) continue;
       if(u==ed&&t.t==st) continue;
        d[t.t]=d[u]+t.val;
       deep[t.t]=deep[u]+1;
       fa[t.t][0]=u;
      dfs2(t.t,u);
      
      }
}

void bz(){
   for(int i=1;i<=30;i++)
      for(int j=1;j<=n;j++)
          fa[j][i]=fa[fa[j][i-1]][i-1];
}
int lca(int a,int b){
  if(deep[a]>deep[b]) swap(a,b);
  int dc=deep[b]-deep[a];
  for(int i=0;i<=30;i++)
     if((1<<i)&dc)
         b=fa[b][i];
  if(a==b) return a;
  for(int i=30;i>=0;i--){
      if(fa[a][i]!=fa[b][i])
      {
         a=fa[a][i];
         b=fa[b][i];
  }
}
a=fa[a][0];
return a;
}
ll solve(int u,int v)
{
  int x=lca(u,v);
  return d[u]+d[v]-2*d[x];
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    init();
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
       int u,v; ll w;
       cin>>u>>v>>w;
       addedge(u,v,w);
    } 
    dfs(1,0);
    dfs2(1,0);
    bz();

    
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        ll ans=solve(u,v);
      //  cout<<ans<<endl;
       // x=lca(u,st);
        //int y=lca(v,ed);
       ans=min(ans,solve(u,st)+solve(v,ed)+sum);
       ans=min(ans,solve(u,ed)+solve(v,st)+sum);
      cout<<ans<<endl;
    }    
  }


  }

