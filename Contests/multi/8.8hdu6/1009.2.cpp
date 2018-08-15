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
const int maxn=100100;
typedef pair<int,int>P;
vector<P>G[maxn];
vector<P>edge[maxn];
vector<int>vec;
int vis[maxn];

void dfs(int u)
{

    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(vis[v]==0) 
         {
             vis[v]=1;
            dfs(v);
           vis[v]=2;
         }
         if(vis[v]==1)
           vec.pb(v);   
    }
}
int ans;
vector<int> Ans;
int id;
void dfs2(int u,int flag)
{
    if(vis[u])
    {
        if(flag==1)
            ans++,Ans.push_back(id);
        return ;
    }
    vis[u]=1;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        if(edge[u][i].sec==1) 
            flag++,id=v;
        if(flag>1) return;
        dfs2(v,flag);
    }
}
void d(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].fir;
        if(vis[v])
            continue;
        if(G[u][i].sec==0)
        {
            ans++;
            d(v);
        }
    }
}
char s[20];
void init(int n)
{
  for(int i=0;i<=n;i++)
  {
      edge[i].clear();
      G[i].clear();
  }
  vec.clear();
  Ans.clear();
  mem(vis,0);
}
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   //cin>>t;
   while(t--)
   {
  
        int n;
       scanf("%d",&n);
      // cin>>n;
           init(n);
       ans=0;
       for(int i=1;i<=n;i++)
       {
          int x;
          scanf("%d%s",&x,s);
          ///cin>>x>>s;
          int flag=0;
          if(s[0]=='w') flag=1;//lang
          edge[i].push_back(mpr(x,flag));
          G[x].push_back(mpr(i,flag));
       }
       for(int i=1;i<=n;i++)
       {
           if(!vis[i])
               dfs(i);
       }
       memset(vis,0,sizeof(vis));
       for(int i=0;i<vec.size();i++)
       {
           dfs2(vec[i],0);
       }
       memset(vis,0,sizeof(vis));
       for(int i=0;i<Ans.size();i++)
       {
           d(Ans[i]);
       }
       printf("0 %d\n",ans);
    }
       }
