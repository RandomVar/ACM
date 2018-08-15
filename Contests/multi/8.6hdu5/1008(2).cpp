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
int getid1(char x)
{
    for(int i=k;i>=1;i--)
      if(a[i]==x-'0')
        return i;
}
int getid2(char x)
{
    int flag=0;
    for(int i=k;i>=1;i--)
      if(flag&&a[i]==x-'0') return i;
      else if(!flag&&a[i]==x-'0') flag=1;
    return 0;
}
int dp(int k)
{
  for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=k;j++)
        dp[i][j]=dp[i-1][j];
    int x1=getid1(s[i]);
     for(int j=1;j<=x1;j++)
        dp[i][x1]=max(dp[i][x1],dp[i-1][j]+1);
     int x2=getid2(s[i])
     if(x2)
     {
         for(int j=1;j<=x2;j++)
           dp[i][x2]=max(dp[i][x2],dp[i-1][j]+1);
     }
  }
  ll x=0;
    for(int j=1;j<=k;j++)
      x=max(x,dp[n][j]);
      return x;
}

void dfs(int pos,int x,int val)
{
    if(pos==0&&val==0) return;
    int x1=getid(s[pos]);
    for(int i=1;i<=x;i++)
     dfs(pos-1,x,val);
   for(int i=1;i<=x1;i++)
   {
         dfs(pos-1,x,val-1);
   }
   int x2=getid(s[pos]);
   if(x2)
   {
       for(int i=1;i<=x2;i++)
       {
           dfs(pos-1,x,val-1);
       }
   }
}

void solve(int u,int v)
{
    int k=0;
   for(int i=0;i<=u;i++)
      a[++k]=i;
    for(int i=v;i>=u;i--)
      a[++k]=i;
    for(int i=v;i<=9;i++)
      a[++k]=i;
    if(ans<dp[k])
      {
        ans=dp[k];
        au=u;
        av=v;     
     }
     dfs(n,k);
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       cin>>s+1;
       for(int i=0;i<=9;i++)
         for(int j=i+1;j<=9;j++)
         {
             solve(i,j);    
         }
   }
 return 0;
  }

