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
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int p1[maxn];
int dep[maxn];
int siz[maxn];
void init1(int n)
{
    for(int i=0; i<=n; i++)
        p1[i]=i;
}
int Find1(int x)
{
    if(x==p1[x])
        return p1[x];
    int y=Find1(p1[x]);
    return p1[x]=y;
}

int Union1(int x,int y)
{
    if(dep[x]>dep[y])
    swap(x,y);
    int x1=Find1(x);
    int y1=Find1(y);
    p1[y1]=x1;
    siz[x1]+=siz[y1];
}

int p2[maxn];
void init2(int n)
{
    for(int i=0; i<=n; i++)
        p2[i]=i;
}
int Find2(int x)
{
    if(x==p2[x])
        return p2[x];
    int y=Find2(p2[x]);
    return p2[x]=y;
}

int Union2(int x,int y)
{
    if(dep[x]>dep[y])
     swap(x,y);

    int x1=Find2(x);
    int y1=Find2(y);

    p2[y1]=x1;
    siz2[x1]+=siz2[y1];
    siz[Find1(fa[y1])]-=siz2[y1];
    int xx=Find1(fa[x1]);
    if(xx!=fa[x1])
    {
        siz[xx]+=siz2[y1];
    }
}

void dfs(int u,int pre)
{
    fa[u]=pre;
    dep[u]=dep[pre]+1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(v==pre) continue;
        int val=edge[u][i].sec;
        if(val==1)
        {
            Union1(u,v);
            Union2(u,v);
        }
        if(val==2)
        {
            Union2(u,v);
        }
        dfs(v,u);
    }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
      int n,m;
      cin>>n>>m;
      for(int i=1;i<n;i++)
      {
          int u,v,c;
          cin>>u>>v>>c;
          edge[u].push_back(mkr(v,c));
          edge[v].push_back(mkr(u,c));
      }
      dfs(1,0);
      for(int i=1;i<=m;i++)
      {
          int s,t;
          cin>>s>>t;
          if()
      }
  }
 return 0;
  }

