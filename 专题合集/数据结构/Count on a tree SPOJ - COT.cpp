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
const int maxn=100010;
int n,m,cnt;
int root[maxn],w[maxn];
int x,y,k;
struct node{
  int l,r,sum;
}T[maxn*40];
int vis[maxn];
int fa[maxn][40];
int deep[maxn];
vector<int>v;
vector<int>edge[maxn];
int getid(int x){
 return lower_bound(v.begin(),v.end(),x)-v.begin()+1;

}
void build(int l,int r,int& rt)
{
    rt=++cnt;
    sum[rt]=0;
    if(l>=r) return;
    int m=(l+r)>>1;
    build(l,m,ls[rt]);
    build(m+1,r,rs[rt]);
}
void update(int l,int r,int &x,int y,int pos){
  T[++cnt]=T[y];
  T[cnt].sum++;
  x=cnt;
  if(l==r) return ;
  int mid=(l+r)/2;
  if(mid>=pos) update(l,mid,T[x].l,T[y].l,pos);
  else update(mid+1,r,T[x].r,T[y].r,pos);

}
int query(int l,int r,int x,int y,int k){
  if(l==r) return l;
  int mid=(l+r)/2;
  int sum=T[T[y].l].sum-T[T[x].l].sum;
  if(sum>=k) return query(l,mid,T[x].l,T[y].l,k);
  else return query(mid+1,r,T[x].r,T[y].r,k-sum);

}
void dfs(int u){
  vis[u]=1;
  if(u!=1) update(1,n,root[u],root[fa[u][0]],getid(u));
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i];
     if(!vis[v]) {

            fa[v][0]=u;//should give fa[v][0] value
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
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(cin>>n>>m){

      for(int i=1;i<=n;i++)
        cin>>w[i];
      for(int i=1;i<n;i++)
         {
             int u,v;
             cin>>u,v;
            edge[u].pb(v);
            edge[v].pb(u);
         }
     dfs(1);
     /*for(int i=1;i<=m;i++){
         int u,v,k;
         cin>>u>>v>>k;

     int t=lca(u,v);
      cout<<query(u,v,root[t],root[fa[t][0]],k)<<endl;
     }*/


   }

return 0;
}
