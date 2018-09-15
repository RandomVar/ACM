#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1100;
ll dp[maxn][7][2];
char s[10];
int a[maxn];
ll op(char c,ll a,ll b)
{
  if(c=='+') return a+b;
  if(c=='*') return a*b;
  if(c=='/') return a/b;
  if(c=='-') return a-b;
}
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
   #endif
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
    }
     scanf("%s",s);
     dp[0][0][1]=dp[0][0][0]=k;
     for(int i=1;i<=n;i++)
     {
       dp[i][0][1]=dp[i][0][0]=k;
       for(int j=1;j<=m&&i>=j;j++)
       {
       ll x1=op(s[j-1],dp[i-1][j-1][1],a[i]);
       ll x2=op(s[j-1],dp[i-1][j-1][0],a[i]);
     if(i==j)
     { dp[i][j][1]=max(x1,x2);
       dp[i][j][0]=min(x1,x2);
     }
    else   {
      dp[i][j][1]=max(dp[i-1][j][1],max(x1,x2));
       dp[i][j][0]=min(dp[i-1][j][0],min(x1,x2));
     }
      //  cout<<i<<" "<<j<<" "<<dp[i][j][1]<<endl;
      }
     }
     printf("%lld\n",dp[n][m][1]);
  }
}
