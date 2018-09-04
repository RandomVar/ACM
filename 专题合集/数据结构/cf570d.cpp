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
const int maxn=5*1e5+100;

vector<int>edge[maxn];
vector< pair<int,int> >q[maxn];
int sz[maxn];
int sum[maxn];
int cnt[maxn][30];
int ans[maxn];
int skip[maxn];
int h[maxn];
char s[maxn];
void init(){
  
     mem(cnt,0);
     mem(sum,0);
     mem(skip,0);
     h[1]=1;    
}
void getsz(int u)
{
    sz[u]=0;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        h[v]=h[u]+1;
        getsz(v);
        sz[v]+=sz[u]+1;
    }
}
void add(int u)
{
    sum[h[u]]-=cnt[h[u]][s[u]-'a'];
    cnt[h[u]][s[u]-'a']^=1;
    sum[h[u]]+=cnt[h[u]][s[u]-'a'];
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(!skip[v]) add(v);
    }
}
void dfs(int u, int keep)
{
    int mx=-1;int bc=-1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(sz[v]>mx)  mx=sz[v],bc=v;
    }
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v!=bc)
          dfs(v,0);
    }
    if(bc!=-1) skip[bc]=1,dfs(bc,1);
    add(u);
    for(int i=0;i<q[u].size();i++)
     ans[q[u][i].sec]=(sum[q[u][i].fir]<=1);
     
    if(bc!=-1) skip[bc]=0;
    if(keep==0) add(u);
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        init();
        int x;
        for(int i=2;i<=n;i++)
         scanf("%d",&x),edge[x].pb(i);
        scanf("%s",s+1);
       getsz(1);
        for(int i=1;i<=m;i++)
        {
            int  v,h;
            scanf("%d%d",&v,&h);
            q[v].push_back(mkr(h,i));
        }
        dfs(1,0);
       for(int i=1;i<=m;i++)
       {
           if(ans[i]) printf("Yes\n");
           else printf("No\n");
       }
    }
 return 0;
  }

