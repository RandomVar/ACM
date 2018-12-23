#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
const int N=30;
vector<int>edge[maxn];
int n;
int fa[maxn][N+5];
int deep[maxn];


void dfs(int u,int pre){
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i];
    if(v==pre) continue;
    fa[v][0]=u;//should give fa[v][0] value
    deep[v]=deep[u]+1; //also can preprocessing distance here
    dfs(v,u);
  }
}

void bz(){
 for(int j=1;j<=N;j++)
    for(int i=1;i<=n;i++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
}

int lca(int u,int v){
  if(deep[u]<deep[v]) swap(u,v);
  int dc=deep[u]-deep[v];
  for(int i=0;i<N;i++){
    if((1<<i)&dc)//move u to dc+u
        u=fa[u][i];
  }
  if(u==v) return u;
  for(int i=N-1;i>=0;i--){
    if(fa[u][i]!=fa[v][i]){
        u=fa[u][i];v=fa[v][i];
    }
  }
  u=fa[u][0];//on the next level of lca,just move up one
  return u;
}
int dis(int x,int y)
{
    return deep[x]+deep[y]-deep[lca(x,y)];
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);

        }
        dfs(1,0);
        bz();
        int  q;
        scanf("%d",&q);
        while(q--)
        {
            int u,v,r;
            scanf("%d%d%d",&r,&u,&v);
            int x=dis(u,r);
            int y=dis(v,r);
            if(x!=y)
              {
                  printf("%d\n",r);
               continue;
              }
              int ans=r;
              for(int i=1;i<=n;i++)
              {
                  if(dis(u,i)==dis(v,i)&&dis(u,i)<x)
                  {
                     x=dis(u,i);
                     ans=i;
                  }
              }
              printf("%d\n",ans);
        }
    }
}