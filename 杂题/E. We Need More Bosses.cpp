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
const int maxn=3*1e5+100;
vector<int>edge[maxn];
vector<int>g[maxn];
stack<int>st;
int low[maxn],dfn[maxn];
int instack[maxn];
int tot;
int scc;//强连通分量个数
int belong[maxn];//记录每个点属于哪个连通分量
int vis[maxn];
void init(){
 mem(dfn,0);
 mem(low,0);
 mem(instack,0);
 //mem(vis,0);
 for(int i=0;i<maxn;i++)
    edge[i].clear(),g[i].clear();
 while(!st.empty())
    st.pop();
 tot=scc=0;
}
void tar(int u,int pre){
  dfn[u]=low[u]=++tot;
  st.push(u);
  instack[u]=1;
  for(int i=0;i<edge[u].size();i++){
     int v=edge[u][i];
     if(v==pre) continue;
     if(!dfn[v]){
        tar(v,u);
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
int bfs(int x){
    mem(vis,0);
  queue<int>que;
  que.push(x);
  vis[x]=1;
  int ans=1;
  int index=0;
  while(!que.empty()){
     int e=que.front();
     que.pop();
     for(int i=0;i<g[e].size();i++){
         int t=g[e][i];
         if(!vis[t])
         {
             que.push(t);
             vis[t]=vis[e]+1;
             if(ans<vis[t]) ans=vis[t],index=t;
            // ans=max(ans,vis[t]);
         }
     }

      }

return index;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m){
        init();
     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         edge[u].pb(v);
         edge[v].pb(u);
     }
    tar(1,0);
    //cout<<1<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<edge[i].size();j++){
            int t=edge[i][j];
            if(belong[i]!=belong[t])
                g[belong[i]].pb(belong[t]);
             // cout<<belong[i]<<" "<<belong[t]<<endl;
        }
    }
    cout<<vis[bfs(bfs(1))]-1<<endl;

  }


}
