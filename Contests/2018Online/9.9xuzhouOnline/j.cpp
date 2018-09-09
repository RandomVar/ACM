#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxm=6e5+100;
const int maxn=3e5;
const int N=22;
int fa[maxn][N+5];
int deep[maxn];
struct node{
  int u,v;ll w;
  bool operator<(const node &b)const{
      return w<b.w;
  }
}edge[maxm];
int p[maxn];
vector<int>G[maxn];
void init(int n)
{
    for(int i=0; i<=n; i++)
        p[i]=i;
}
int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}
int Union(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)
        return 0;
    p[x1]=y1;
    G[y].pb(x);
    G[x].pb(y);
      return 1;
}

void kruskal(int n,int m)
{
  ll sum=0;//生成树的总权值
  int num=0;//已选用的边的数目
  init(n);
  sort(edge,edge+m);
  for(int i=m-1;i>=0;i--)
  {
    int u=edge[i].u;
    int v=edge[i].v;
    ll w=edge[i].w;

      if(Union(u,v))
      {
        num++;sum+=w;
      }
  if(num==n-1) break;
  }
}

void dfs(int u,int pre){
  for(int i=0;i<G[u].size();i++){
    int v=G[u][i];
    if(v==pre) continue;
    fa[v][0]=u;//should give fa[v][0] value
    deep[v]=deep[u]+1; //also can preprocessing distance here
    dfs(v,u);
  }
}

void bz(int n){
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

void Init(int n)
{
  for(int i=0;i<=n;i++)
    G[i].clear();
    deep[1]=0;
    fa[1][0]=0;
}

int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
      Init(n*m);
      char s1[10];char s2[10];ll a,b;
      int k=0;
      for(int i=1;i<=n*m;i++)
      {
          scanf("%s%lld%s%lld",s1,&a,s2,&b);
          if(s1[0]!='X')
          {
            edge[k].u=i;
            edge[k].v=i+m;
            edge[k].w=a;
            k++;

          }//a[i][i+m]=a;
          if(s2[0]!='X') //a[i][i+1]=b;
        {
          edge[k].u=i;
          edge[k].v=i+1;
          edge[k].w=b;
           k++;

        }
      }
      kruskal(n*m,k);
      dfs(1,0);
      bz(n*m);
      int q;
      scanf("%d",&q);
      for(int i=1;i<=q;i++)
      {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int u=(x1-1)*m+y1;
        int v=(x2-1)*m+y2;
        int ans=deep[u]+deep[v]-2*deep[lca(u,v)];
        // cout<<lca(u,v)<<endl;
        // cout<<deep[u]<<" "<<deep[v]<<deep[lca(u,v)]<<endl;
         printf("%d\n",ans);
      }

    }
 return 0;
  }
