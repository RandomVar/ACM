#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
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
typedef pair<int,int> P;
vector<P>edge[1100];
vector<int>vec;
int w[1100],d[1100];
int dis[1100];
int n;
int ans[1100],dp[1100][1100];
void dfs2(int u,int pre)
{ 
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        int w=edge[u][i].sec;
        if(v==pre) continue;
        dis[v]=dis[u]+w;
        dfs2(v,u);
    }
}

void dfs1(int u,int pre)
{
    dp[u][u]=w[u];
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        
        if(v==pre) continue;
        dfs1(v,u);
    }
     ans[u]=inf;
     dis[u]=0;
     dfs2(u,0);
        for(int j=1;j<=n;j++)
        {
            if(dis[j]-dis[u]<=d[u])
            {
             dp[u][j]=w[j];
               for(int i=0;i<edge[u].size();i++)
               {
                    int v=edge[u][i].fir;
                     dp[u][j]+=min(dp[v][j]-w[j],ans[v]);
                    // cout<<dp[u][j]<<endl;
              }
              ans[u]=min(ans[u],dp[u][j]);
              //cout<<ans[u]<<endl;
           }
        }
}

void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
    mem(ans,0);
   mem(dp,0x3f);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
       // int n;
        cin>>n;
        init();
        for(int i=1;i<=n;i++)
         cin>>w[i];
        for(int i=1;i<=n;i++)
        cin>>d[i];
        for(int i=1;i<n;i++)
        {
            int u,v,k;
            cin>>u>>v>>k;
            edge[u].push_back(mpr(v,k));
            edge[v].push_back(mpr(u,k));
        }
        //dis[1]=0;
       // dfs2(1,0);
        dfs1(1,0);
        cout<<ans[1]<<endl;
    }
 return 0;
  }

