#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int dp[100][100];
int f[100][100][5];
vector<int>v;
int cnt;
void dfs(int x,int y)
{
    if(x==0||y==0)
      {
          cnt++;
           int c=v.size();
           for(int i=c-1;i>=0;i--)
            cout<<v[i];
         cout<<endl;
       return;
       }
    
    if(f[x][y][1]==1)
      dfs(x-1,y);
    if(f[x][y][2]==1)
      dfs(x,y-1);
    if(f[x][y][3]==1)
    {
      v.push_back(x);
      dfs(x-1,y-1);
      v.pop_back();
    }
  
}
int main()
{
    int t;int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        getchar();
        for(int i=1;i<=m;i++)
         scanf("%c",&a[i]),getchar();
        for(int i=1;i<=n;i++)
         scanf("%c",&b[i]),getchar();
         memset(dp,0,sizeof(dp));
     for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
      {
         if(dp[i-1][j]>=dp[i][j-1])
         {
             f[i][j][1]=1;
             dp[i][j]=dp[i-1][j];
         }
         if(dp[i][j-1]>=dp[i-1][j])
           f[i][j][2]=1,dp[i][j]=dp[i][j-1];
         
         if(a[i]==b[j])
         {
             if(dp[i][j]==dp[i-1][j-1]+1)
             {
                 f[i][j][3]=1;
                 dp[i][j]=dp[i-1][j-1]+1;
             }
             if(dp[i][j]<dp[i-1][j-1]+1)
             {
                 f[i][j][1]=f[i][j][2]=0;
                 f[i][j][3]=1;
                 dp[i][j]=dp[i-1][j-1]+1;
             }
         }
        //   cout<<a[i]<<endl;
        //    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //   if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
              
      }
      printf("Case %d\n%d\n",++cas,dp[m][n]);
      cnt=0;
       dfs(m,n);
       printf("%d\n",cnt);
    }
}


