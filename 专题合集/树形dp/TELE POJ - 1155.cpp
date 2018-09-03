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
const int maxn=3500;
int n;
typedef pair<int,int> P;
vector<P>edge[maxn];
int dp[maxn][maxn];
int dfs(int u,int pre)
{
   if(edge[u].size()==0) return 1;
    int  sum=1;
  for(int i=0;i<edge[u].size();i++)
  {
      int v=edge[u][i].fir;
      int w=edge[u][i].sec;
      if(v==pre) continue;
      sum+=dfs(v,u);
      //cout<<sum<<endl;
     for(int s=sum;s>=1;s--)
        for(int j=0;j<=s;j++)
            dp[u][s]=max(dp[u][s],dp[u][s-j]+dp[v][j]-w);
  }
  return sum;
}

void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
     mem(dp,-0x3f);
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   while(cin>>n)
   {
       init();
       int m;
       cin>>m;
     for(int i=1;i<=n-m;i++)
     {
       int k;
       cin>>k;
       for(int j=1;j<=k;j++)
       {
           int a,c;
           cin>>a>>c;
           edge[i].push_back(mpr(a,c));
           edge[a].push_back(mpr(i,c));
       }
      }
      for(int i=0;i<=n;i++)
        dp[i][0]=0;
      for(int i=n-m+1;i<=n;i++)
          cin>>dp[i][1];
      dfs(1,0);
  /*   for(int i=1;i<=n;i++)
     {
       for(int j=1;j<=m;j++)
        cout<<dp[i][j]<<" ";
     cout<<endl;
     }*/
     for(int i=m;i>=0;i--)
       if(dp[1][i]>=0)
         {cout<<i<<endl;break;}
   }
 return 0;
  }

/*

*/