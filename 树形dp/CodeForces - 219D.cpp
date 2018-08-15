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
const int maxn=2e5+100;
typedef pair<int,int> P;
vector<P>edge[maxn];
int d[maxn];//int f[maxn];
int ans[maxn];
int n;
void dfs1(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        int flag=edge[u][i].sec;
        if(v==pre) continue;
        dfs1(v,u);
        d[u]+=d[v]+flag;
       // f[u]+=f[v]+(flag==0?1:0);
    }
}
void dfs2(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        int flag=edge[u][i].sec;
        if(v==pre) continue;
        ans[v]=ans[u]+(flag==0?1:-1);
        //ans[v]=ans[u]+(f[u]-f[v])*2+(d[v]-d[u)*2;
        dfs2(v,u);
    }
}
void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
     mem(d,0);
    // mem(f,0);
     mem(ans,0);
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   // int n;
    while(cin>>n)
    {
        init();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(mpr(v,0));//zheng
            edge[v].push_back(mpr(u,1));//fanxiang
            //edge[v].pb(u);
        }
        dfs1(1,0);
        ans[1]=d[1];
        dfs2(1,0);
        int daan=inf;
      //  for(int i=1;i<=n;i++)
        // cout<<i<<" "<<d[i]<<" "<<f[i]<<" "<<ans[i]<<endl;
        for(int i=1;i<=n;i++)
        {
            if(daan>ans[i])
              daan=ans[i];
        }
        cout<<daan<<endl;
        for(int i=1;i<=n;i++)
        {
              if(daan==ans[i]) cout<<i<<" ";
        }
        cout<<endl;
       

         
    }
 return 0;
  }

