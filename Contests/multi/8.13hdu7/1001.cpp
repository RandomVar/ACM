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
const int maxn=1e5+10;
vector<pair<int,int> >edge[maxn];
queue<int>que;
int vis[maxn];
int n,m;
void dfs(int u,int flag)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(!vis[v]&&flag==edge[u][i].sec)
        {
            vis[v]=vis[u];
            que.push(v);
            dfs(v,flag);
        }
    }
}

int bfs()
{
    que.push(1);
    vis[1]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        if(u==n) return vis[u]-1;
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i].fir;
            if(!vis[v])
            {
                vis[v]=vis[u]+1;
                dfs(v,edge[u][i].sec);
                que.push(v);
            }

        }
    }
    return -1;
}
void init()
{
    for(int i=0;i<=n;i++)
    {
        edge[i].clear();
        vis[i]=0;
    }
    while(!que.empty())
    {
        que.pop();
    }
}
int main(){
   freopen("data.in","r",stdin);
  freopen("data.out","w",stdout);
   while(scanf("%d%d",&n,&m)==2)
   {
       init();
 
       for(int i=1;i<=m;i++)
       {
           int u,v,c;
           scanf("%d%d%d",&u,&v,&c);
           edge[u].push_back(mpr(v,c));
           edge[v].push_back(mpr(u,c));
         
       }
          printf("%d\n",bfs());
        
         
   }
 return 0;
  }