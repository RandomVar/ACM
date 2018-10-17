#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int dp[100][100];
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
        //   cout<<a[i]<<endl;
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
      }
      printf("Case %d\n%d\n",++cas,dp[m][n]);
    }
}