/**
增加一条边u v之后，u v的最近公共祖先的子树上的割边变成普通边

*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<sstream>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100100;//remind to change it
vector<int>edge[maxn];
int low[maxn],dfn[maxn],cut,tot;
bool iscut[maxn];
int fa[maxn];
int deep[maxn];
int n;
void init(){
    for(int i = 0; i <= n; i++)
        edge[i].clear();
        mem(low);
        mem(dfn);
        mem(iscut);
        mem(fa);
        mem(deep);
       cut = 0;tot=0;
}
void dfs(int u,int f){
    fa[u]=f;
    deep[u]=deep[f]+1;
    low[u] = dfn[u] = ++tot;
    int child=0;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!dfn[v]){
            dfs(v,u);
            child++;
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]){
                iscut[v] = true;
                cut++;}
        }
        else if(v != f){
            low[u] = min(low[u],dfn[v]);
        }
    }
    //if(f<0&&child == 1) {iscut[u] = 0;cut--;}
}
void lca(int u,int v){
  while(deep[u]>deep[v]){
     if(iscut[u]) {cut--;iscut[u]=0;}
     u=fa[u];
  }
  while(deep[v]>deep[u]){
     if(iscut[v]) {cut--;iscut[v]=0;}//don't mix up u,v
     v=fa[v];
  }
  while(u!=v){
    if(iscut[u]) {cut--;iscut[u]=0;}
    if(iscut[v]) {cut--;iscut[v]=0;}
    u=fa[u];v=fa[v];
  }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //int n;
  int m;int kk=0;
  while(cin>>n>>m&&n&&m){
        init();
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    deep[0]=0;
     dfs(1,0);
    int q;
    cin>>q;
    cout<<"Case "<<++kk<<":"<<endl;//attention pattern
   for(int i=0;i<q;i++){
       int x,y;
       cin>>x>>y;
       lca(x,y);
      cout<<cut<<endl;
   }
  cout<<endl;
  }
return 0;
}
