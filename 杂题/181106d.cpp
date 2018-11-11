#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[60][60][60];
ll cost[60][60][60];
const ll inf=1e10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int main()
{
    int n,m,c;
    while(scanf("%d%d%d",&n,&m,&c))
    {
        for(int i=0;i<=n;i++)
         for(int j=0;j<=n;j++)
         {
          cost[i][j][0]=0;
          cost[i][j][1]=inf;
         }
         int x,y,z;
        for(int i=1;i<=m;i++)
        {
         scanf("%d%d%d",&x,&y,&z);
         cost[x][y][0]=max(cost[x][y][0],1LL*z);
         cost[x][y][1]=min(cost[x][y][1],1LL*z);
        }
        for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
         {
             if(i==j) dp[i][j][0]=0;
             else dp[i][j][0]=cost[i][j][1];
         }
       for(int k=1;k<n;k++)
        for(int x=1;x<=n;x++)
        for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
        {
            dp[i][j][k]=min(dp[i][j][k],dp[i][x][k-1]-cost[x][j][0]);
            dp[i][j][k]=min(dp[i][j][k],dp[i][x][k]+cost[x][j][1]);
        }
        ll ans=INF;
        for(int x=1;x<=n;x++)
        {
            for(int k1=0;k1<n;k1++)
              for(int k2=0;k2<n;k2++)
                for(int k3=0;k3<n;k3++)
                {
                    int y=c-k1-k2;
                    if(y%k3) continue;
                    int z=y/k3;
                    ans=min(ans,dp[1][x][k1]+dp[x][x][k3]*z+dp[x][n][k2]);
                }
        }
        printf("%lld\n",ans);
        
    }
}
