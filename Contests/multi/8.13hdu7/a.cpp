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
int ans;
int n,m;
int vis[maxn];
bitset<maxn*10>mp;
queue<int>que;
void dfs(int u,int cnt)
{
    if(u==n) {

        ans=min(ans,cnt);
        return;
    }
  
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(vis[v]==1) continue;
        if(!mp[edge[u][i].sec])
          {
              if(cnt+1<ans)
              {
             cnt++;
             vis[v]=1;
             mp[edge[u][i].sec]=1;
             dfs(v,cnt);
             cnt--;
             vis[v]=2;
             mp[edge[u][i].sec]=0;
              }
          }
        else if(cnt<ans)
        {
            vis[v]=1;
            dfs(v,cnt);
            vis[v]=2;
        }

    }
}
int dfs2(int u,int flag)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(!vis[v]&&flag==edge[u][i].sec)
        {
            vis[v]=vis[u];
            que.push(v);
            if(v==n) return 1;
            dfs(v,flag);
        }
    }
    return 0;
}
int bfs()
{
    que.push(1);
    vis[1]=1;
    for(int i=0;i<edge[1].size();i++)
    {
        int v=edge[1][i].fir;
        if(!vis[v])
        {
            vis[v]=vis[1]+1;
             que.push(v);
            if(v==n) return 1;
            if(dfs2(v,edge[1][i].sec)==1)
               return 1;
        }
    }
    return 0;
}

void init()
{
    for(int i=0;i<=n;i++)
    {
        edge[i].clear();
        vis[i]=0;
    }
}

int main(){

   while(scanf("%d%d",&n,&m)==2)
   {
       init();
      // init2();
       for(int i=1;i<=m;i++)
       {
           int u,v,c;
           scanf("%d%d%d",&u,&v,&c);
           edge[u].push_back(mpr(v,c));
           edge[v].push_back(mpr(u,c));
          // unin(u,v);
       }
  
      ans=bfs();
      if(ans==1)
        printf("1\n");
    else{  
          ans=m+1;
           dfs(1,0); 
        if(ans==m+1)
         printf("-1\n");
         else 
           printf("%d\n",ans);
       }
   }
 return 0;
  }