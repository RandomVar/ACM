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
const int maxn=400;
vector<int>edge[maxn];
int vis[maxn];

int bfs(int m)
{
    queue<int>que;
    mem(vis,0);
      que.push(0);
       vis[0]=1;
       while(!que.empty())
       {
           int t=que.front();
           que.pop();
          // cout<<t<<endl;
           for(int i=0;i<edge[t].size();i++)
           {
               int v=edge[t][i];
              // cout<<v<<endl;
               if(vis[v]) continue;
               vis[v]=vis[t]+1;
               que.push(v);
               //cout<<vis[v]<<endl;
              // cout<<m<<endl;
               if(v==m) return vis[v];
           }
       }
       return 0;
}
void init(int n)
{
    for(int i=0;i<=n+2;i++)
     edge[i].clear();
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int m,n;
  while(scanf("%d%d",&m,&n)==2)
  {
      init(max(n,m));
      for(int i=1;i<=n;i++)
      {
          int u,v;
          scanf("%d%d",&u,&v);
          edge[u].pb(v);
      }
      for(int i=0;i<=max(n,m);i++)
       {
           edge[i].pb(i+1);
           edge[i+1].pb(i);
       }
       printf("%d\n",bfs(m)-1);
    
      
  }
 return 0;
  }

