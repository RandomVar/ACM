/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=40010;
struct node{
  int t,val;
};
int n;
int vis[maxn];
int fa[maxn][40];
int deep[maxn],d[maxn];
vector<node>edge[maxn];
int cnt;
void addedge(int u,int v,int val){
//  e.pb(node{u,v,val});
  edge[u].push_back(node{v,val});
  edge[v].push_back(node{u,val});
}
void dfs(int u){
  vis[u]=1;
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i].t;
     if(!vis[v]) {
            fa[v][0]=u;//should give fa[v][0] value
            d[v]=d[u]+edge[u][i].val;
            deep[v]=deep[u]+1;
            dfs(v);
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

int main(){
   int t;
   cin>>t;
   while(t--){
    int m;
   cin>>n>>m;
    mem(vis);
    for(int i=0;i<=n;i++)
        edge[i].clear();
    for(int i=1;i<n;i++){
        int u,v,k;
        cin>>u>>v>>k;
        addedge(u,v,k);
    }
    d[1]=0;
    fa[1][0]=0;
    dfs(1);
    bz();
    ll ans=0;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        int t=lca(x,y);
        ans=d[x]+d[y]-2*d[t];
       cout<<ans<<endl;
    }

   }


}
