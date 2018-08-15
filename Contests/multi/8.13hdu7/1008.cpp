#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
struct node{
   int to;ll cost;int id;
};
vector<node>edge[maxn];
int id[maxn],val[maxn];
int st[maxn],ed[maxn];
int tot;
int n;
int ss,ee,ssum,ii;
void dfs(int u,int pre)
{
    st[u]=++tot;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].to;
        if(v==pre) continue;
        id[edge[u][i].id]=v;
        if(st[v])
          {
              ss=u;
              ee=v;
              ii=edge[u][i].id;
              ssum=edge[u][i].cost;
              continue;
          }
             dfs(v,u);
    }
    ed[u]=tot;
}
ll bit[maxn];

int lowbit(int x){
return x&(-x);
}
ll sum(int x){
  ll ret=0;
  while(x>0){
    ret+=bit[x];
    x-=lowbit(x);
  }
return ret;
}

void add(int x,ll d){
    if(x<0) return;
   while(x<=n){
    bit[x]+=d;
    x+=lowbit(x);
   }
}

const int N=30;
int fa[maxn][N+5];
int deep[maxn];
ll d[maxn];

void dfs2(int u,int pre){
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i].to;
    if(v==pre) continue;
    if(v==ss&&u==ee) continue;
    if(v==ee&&u==ss) continue;
    fa[st[v]][0]=st[u];//should give fa[v][0] value
    deep[st[v]]=deep[st[u]]+1; //also can preprocessing distance here
    add(st[v],edge[u][i].cost);
    add(ed[v]+1,-edge[u][i].cost);
    //d[st[v]]=d[st[u]]+edge[u][i].cost;
    dfs2(v,u);
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
ll solve(int u,int v)
{
    return sum(st[u])+sum(st[v])-2*sum(lca(st[u],st[v]));
}
void init()
{
    for(int i=0;i<=n+1;i++)
    {
        edge[i].clear();
        bit[i]=0;
        st[i]=0;
    }
    tot=0;
    
}
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int q;
       scanf("%d%d",&n,&q);
       init();
       for(int i=1;i<=n;i++)
       {
           int u,v,w;
           scanf("%d%d%d",&u,&v,&w);
           edge[u].push_back(node{v,w,i});
           edge[v].push_back(node{u,w,i});
           val[i]=w;
       }
       dfs(1,0);
       dfs2(1,0);
       bz();
    //   cout<<ss<<" "<<ee<<endl;
       for(int i=1;i<=q;i++)
       {
           int op,x,y;
           scanf("%d%d%d",&op,&x,&y);
           if(op==0)
           {
               if(x==ii) ssum=y;
               else
               {
               add(st[id[x]],y-val[x]);
               add(ed[id[x]]+1,-y+val[x]);
               val[x]=y;
              }
           }
           else
           {
                 ll ans=solve(x,y);
                 ans=min(ans,solve(x,ss)+solve(y,ee)+ssum);
                 ans=min(ans,solve(x,ee)+solve(y,ss)+ssum);
                printf("%lld\n",ans);
           }
       }
   }
 return 0;
  }

