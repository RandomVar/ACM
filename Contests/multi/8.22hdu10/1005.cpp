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
int tot,ma;
vector<int>edge[maxn];
vector<int>pos[maxn];
vector<int>vec;
int ans[maxn];
const int N= 30;
int n;
int fa[maxn][N+5];
int deep[maxn];
int st[maxn];

void dfs(int u){
    st[u]=++tot;
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i];
    fa[v][0]=u;//should give fa[v][0] value
    deep[v]=deep[u]+1; //also can preprocessing distance here
    dfs(v);
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
int cmp(int x,int y)
{
    return st[x]<st[y];
}
void solve(int g)
{
    vec.clear();
    for(int i=g;i<=ma;i+=g)
    {
        for(int j=0;j<pos[i].size();j++)
           vec.pb(pos[i][j]);
    }
    sort(vec.begin(),vec.end(),cmp);
    if(vec.size()<=1) return;
    for(int i=0;i<vec.size()-1;i++)
      {
          int p=lca(vec[i],vec[i+1]);
         ans[p]=max(ans[p],g);
      }
}
void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
     mem(ans,-1);
     ma=0;
     for(int i=0;i<=1e5;i++)
       pos[i].clear();
      tot=0;
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    while(scanf("%d",&n)==1)
    {
        init();
       for(int i=2;i<=n;i++)
        {
            int u;
           scanf("%d",&u);
           edge[u].pb(i);
        }
        for(int i=1;i<=n;i++)
        {
            int v;
            scanf("%d",&v);
            pos[v].pb(i);
            ma=max(ma,v);
        }
        dfs(1);
        bz();
        for(int i=1;i<=ma;i++)
           solve(i);
        for(int i=1;i<=n;i++)
         printf("%d\n",ans[i]);
    }
 return 0;
  }

