/*
n个点的树有k种颜色涂，求同种颜色间的最小距离为d的方案数

= 最小距离大于等于d+1的方案数-最小距离大于等于d的方案数
bfs可求得
*/
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
const int mod=1e9+7;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn= 6000;
int n,k;
vector<int>edge[maxn];
int dis[maxn][maxn];
int v[maxn];

void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
     mem(dis,0);
     //ans=1;

}
void dfs(int s,int x,int pre)
{
   for(int i=0;i<edge[x].size();i++)
   {
       int t=edge[x][i];
       if(t==pre) continue;
       dis[s][t]=dis[s][x]+1;
       dfs(s,t,x);
   }
}
ll bfs(int d)
{
    ll ans=1;
    for(int i=1;i<=n;i++)
      v[i]=k;
    queue<int>que;
    que.push(1);
    while(!que.empty())
    {
        int t=que.front();
        que.pop();
        for(int i=1;i<=n;i++)
        {
            if(i==t) continue;
            if(dis[t][i]<d)
              v[i]--;
             
        }
         if(v[t]<=0) return 0LL;
        ans=(ans*v[t])%mod;
        for(int i=0;i<edge[t].size();i++)
        {
            int v=edge[t][i];
            if(dis[1][v]==dis[1][t]+1)
              que.push(v);
        }
    }
    return ans;
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int d;
   while(cin>>n>>k>>d)
   {
       init();
       for(int i=1;i<n;i++)
       {
           int u,v;
           cin>>u>>v;
           edge[u].pb(v);
           edge[v].pb(u);
       }
       for(int i=1;i<=n;i++)
       {
           dfs(i,i,-1);
       }
     //  cout <<bfs(d+1)<<" "<<bfs(d)<<endl;
    cout<<(bfs(d)-bfs(d+1)+mod)%mod<<endl;
   } 

 return 0;
  }

