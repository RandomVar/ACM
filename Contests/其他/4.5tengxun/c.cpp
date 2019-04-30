#include<bits/stdc++.h>
using namespace std;
int dp[150][150][3];

const int N=102;
int c[N+5][N+5];
void init(){
for(int j=0;j<N;j++)
    c[j][0]=1;
for(int i=0;i<N;i++)
   for(int j=1;j<N;j++)
    {
     if(i==j) c[i][j]=1;
      else if(i<j) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i-1][j]); 
    }
}
int vis[110];
int n;
int check()
{
  for(int i=1;i<=2*n;i++)
  {
      if(vis[i]==1)
      {
        a.push(i);
      }
      else b.push
  }
}

void dfs(int pos,int num)
{
 if(num==n)
 {
  ans+=check();
 }
  for(int i=pos+1;i<=2*n;i++)
   {
    vis[i]=1;
   dfs(i,num+1);
    vis[i]=0;
   }
}
int main()
{
  int n,k;
  init();
  while(cin>>n>>k)
  {
    dfs(1,1);
  //   n*=2;
  //   if(k==1)
  //   {
  //     cout<<c[n*2][n]<<endl;
  //     continue;
  //   }
  //    memset(dp,0,sizeof(dp));
  //    dp[1][0][0]=dp[1][1][1]=1;
  //  for(int i=1;i<=n;i++)
  //     dp[i][0][0]=1;
  //  for(int i=1;i<=k;i++)
  //   dp[i][1][1]=1;
  //   for(int i=2;i<=n;i++)
  //    for(int j=1;j<=k;j++)
  //    {
  //   if(i>k)  dp[i][j][1]=dp[i-k][j-1][1]+dp[i-k][j][0];
  //      dp[i][j][0]=dp[i-1][j][1]+dp[i-1][j][0];
  //    }
  //   //  for(int i=1;i<=n;i++)
  //   //   for(int j=1;j<=k;j++)
  //   //    cout<<i<<" "<<j<<" :"<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
  //    cout<<dp[n][n/2][1]+dp[n][n/2][0]<<endl;
  }
}