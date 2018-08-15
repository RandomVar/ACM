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
const int maxn=1e5+100;;
struct node{
  int t,v1,v2;
};
int n;
int vis[maxn];
int fa[maxn][40];
int deep[maxn],d[maxn],d2[maxn];
vector<node>edge[maxn];
//int cnt;

void dfs(int u,int pre){
  vis[u]=1;
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i].t;
    if(v==pre) continue;
     if(!vis[v]) {
            fa[v][0]=u;//should give fa[v][0] value
            d[v]=d[u]+edge[u][i].v1;
            d2[v]=d2[u]+edge[u][i].v2;
            deep[v]=deep[u]+1;
            dfs(v,u);
     }
  }
}

void bz(){
 for(int j=1;j<=30;j++)
    for(int i=1;i<=n;i++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
}

int lca(int u,int v){
  if(deep[u]<deep[v]) swap(u,v);
  int dc=deep[u]-deep[v];
  for(int i=0;i<30;i++){
    if((1<<i)&dc)//move u to dc+u
        u=fa[u][i];
  }
  if(u==v) return u;
  for(int i=29;i>=0;i--){
    if(fa[u][i]!=fa[v][i]){
        u=fa[u][i];v=fa[v][i];
    }
  }
  u=fa[u][0];//on the next level of lca,just move up one
  return u;
}
void init(){
  for(int i=0;i<=n;i++)
  edge[i].clear();
  mem(deep,0);
  mem(d,0);
 // mem(fa,0);
  mem(vis,0);
  mem(d2,0);
}
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  //cin>>t;
  while(t--){
  scanf("%d",&n);
    //cin>>n;
    init();
    ll ans=0;
    for(int i=1;i<n;i++){
        int u,v,c1,c2;
        scanf("%d%d%d%d",&u,&v,&c1,&c2);
        //cin>>u>>v>>c1>>c2;
        edge[u].push_back(node{v,c1,c2});
        edge[v].push_back(node{u,c2,c1});
     ans+=c1+c2;
    }
    dfs(1,0);
    bz();
    int q;
    scanf("%d",&q);
    //cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
       // cin>>x>>y;
        int t=lca(x,y);
        printf("%lld\n",ans-((d[x]-d[t])+(d2[y]-d2[t])));
       // cout<<ans-((d[x]-d[t])+(d2[y]-d2[t]))<<endl;
   // cout<<ans-((d[y]-d[t])+(d2[x]-d2[t]))<<endl;

    }


  }


  }

