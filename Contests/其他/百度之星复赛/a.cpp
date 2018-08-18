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
const int maxn=1e5+100;
ll a[maxn];
vector<int>edge[maxn];
ll f[maxn][3][3];
void dfs(int u,int pre)
{
      ll ansmax=0;ll ansmin=0;
      ll sonmax=0;ll sonmin=0;
      ll sonmax2=0;ll sonmin2=0;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==pre) continue;
        dfs(v,u);
       f[u][0][0]+=f[v][0][0];//max
       f[u][0][1]+=f[v][0][1];//min
      ansmax=max(ansmax,f[v][1][0]-f[v][0][0]);
      ansmin=min(ansmin,f[v][1][1]-f[v][0][1]);
      if(sonmin>a[v])
      {
          sonmin2=sonmin;
          sonmin=a[v];
          
      }
      else if(sonmin2>a[v])
      {
          sonmin2=a[v];
      }
      if(sonmax<a[v])
      {
           sonmax2=sonmax;
          sonmax=a[v];
         
      }
      else if(sonmax2<a[v])
      {
          sonmax2=a[v];
      }
    }
   //cout<<u<<" "<<ansmax<<" "<<ansmin<<endl;
      f[u][0][0]+=sonmax;
      f[u][0][1]+=sonmin;
     f[u][1][0]=ansmax+f[u][0][0];
     f[u][1][1]=ansmin+f[u][0][1];
      f[u][1][0]=max(f[u][1][0],f[u][0][0]+sonmax2);
      f[u][1][1]=min(f[u][1][1],f[u][0][1]+sonmin2);
    //f[u][1][0]=f[u][0][0];
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
         edge[i].clear();
        for(int i=2;i<=n;i++)
        {
            int v;
            scanf("%d",&v);
            edge[v].pb(i);
        }
        for(int i=1;i<=n;i++)
         scanf("%lld",&a[i]);
         mem(f,0);
        dfs(1,0);
        ll ansmax=-INF;ll ansmin=INF;
      
        for(int i=1;i<=n;i++)
          {
             // cout<<i<<" "<<f[i][0][1]<<" "<<f[i][1][1]<<endl;
            ansmax=max(ansmax,max(f[i][1][0],f[i][0][0])+max(a[i],0LL));
            ansmin=min(ansmin,min(f[i][1][1],f[i][0][1])+min(a[i],0LL));
          }
          printf("%lld %lld\n",ansmax,ansmin);
    }
 return 0;
  }
