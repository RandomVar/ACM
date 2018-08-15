#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int edge[1010][1010];
int vis[1010];
int n;int tdfn;int son;
int dfn[1010];
int low[1010];
int subn[1010];
void dfs(int u){
 for(int v=1;v<=n;v++){
    if(edge[u][v]){
        if(!vis[v]){
            vis[v]=1;
            tdfn++;dfn[v]=low[v]=tdfn;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                if(u!=1) subn[u]++;
                if(u==1) son++;
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
 }
}
void init(){
 memset(vis,0,sizeof(vis));
 low[1]=dfn[1]=1;
 tdfn=1;son=0;
 vis[1]=1;
 memset(subn,0,sizeof(subn));
}
int main(){
  int x,y;int k=0;
  while(cin>>x){
    k++;n=0;
    if(x==0) break;
    memset(edge,0,sizeof(edge));
    cin>>y;
    n=max(n,x);
    n=max(n,y);
    edge[x][y]=1;
    edge[y][x]=1;
    int x1,y1;
    while(cin>>x1){
      if(x1==0) break;
      cin>>y1;
       n=max(n,x1);
       n=max(n,y1);
      edge[x1][y1]=1;
      edge[y1][x1]=1;
    }
    init();
    dfs(1);int flag=0;
    if(k>1) cout<<endl;
    cout<<"Network #"<<k<<endl;
    //cout<<n<<endl;
    if(son>=2) {flag=1;cout<<"  SPF node 1 leaves "<<son<<" subnets"<<endl;}
    for(int i=2;i<=n;i++){
        if(subn[i]) {flag=1;cout<<"  SPF node "<<i<<" leaves "<<subn[i]+1<<" subnets"<<endl;}
    }
    if(flag==0) cout<<"  No SPF nodes"<<endl;
  }
}
