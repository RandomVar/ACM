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
const int maxn=1e5+100;
struct tree{
 int l,r,sum;

}T[maxn*40];
int cnt,n;
int root[maxn];
vector<int>edge[maxn];
int st[maxn];
int a[maxn];
vector<int>v;
int getid(int x){
 return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int vis[maxn];
int fa[maxn][40];
int deep[maxn];

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

void init()
{
    cnt=0;
    root[0]=0;
    T[0].l=T[0].r=T[0].sum=0;
    deep[0]=0;
    v.clear();
}
void update(int l,int r,int &x,int y,int pos)
{
    
    T[++cnt]=T[y];
    T[cnt].sum++;
    x=cnt;
    if(l==r) return;
    int mid=(l+r)/2;
    if(pos<=mid)
       update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}

int query(int l,int r,int x,int y,int lca,int flca,int k)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    int sum=T[T[y].l].sum+T[T[x].l].sum-T[T[lca].l].sum-T[T[flca].l].sum;
    if(k<=sum) return query(l,mid,T[x].l,T[y].l,T[lca].l,T[flca].l,k);
    else return query(mid+1,r,T[x].r,T[y].r,T[lca].r,T[flca].r,k-sum);
}

void dfs(int u,int pre){ 
  
  update(1,n,root[u],root[pre],getid(a[u]));
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i];
    if(v==pre) continue;
    fa[v][0]=u;//should give fa[v][0] value
    deep[v]=deep[u]+1;
    dfs(v,u);
     
  }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   while(scanf("%d%d",&n,&m)==2)
   {
       init();
       for(int i=1;i<=n;i++)
         scanf("%d",&a[i]),v.push_back(a[i]);
          sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
       for(int i=1;i<=n-1;i++)
       {
           int u,v;
           scanf("%d%d",&u,&v);
           edge[u].pb(v);
           edge[v].pb(u);
       }
        dfs(1,0); 
        bz();

        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int lc=lca(a,b);
            printf("%d\n",v[query(1,n,root[a],root[b],root[lc],root[fa[lc][0]],c)-1]);
        }
   }

 return 0;
  }

