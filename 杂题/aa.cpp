#include<bits/stdc++.h>
using namespace std;
int dp[30][30100];
int a[30];
int main()
{
     #ifndef ONLINE_JUDGE
    freopen("loading.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
    int n;int cas=0;
    while(scanf("%d",&n)==1)
    {
        int sum=0;int c1,c2;
        for(int i=1;i<=n;i++)
         scanf("%d",&a[i]),sum+=a[i];
        scanf("%d%d",&c1,&c2);
      
      memset(dp,0,sizeof(dp));
      dp[n+1][c1]=1;
      for(int i=n;i>=1;i--)
       for(int k=n+1;k>i;k--)
        for(int j=c1;j>=a[i];j--)
        {
            if(dp[k][j])
            {
               dp[i][j-a[i]]=1;
            //    cout<<"!"<<i<<" "<<j-a[i]<<endl;
            }
        }
        int flag=0;
            printf("Case %d\n",++cas);
        for(int i=1;i<=n;i++)
        {
            int ans=0;
            for(int j=0;j<=c1;j++)
              {
                  if(dp[i][j]==1)
                  {
                      ans=c1-j;
                      break;
                  }
              }
              if(sum-ans>c2)
              {
                  continue;
              }
              else
              {
                  printf("%d ",ans);
                  flag=1;
                  int x=c1-ans;
                  for(int k=1;k<i;k++)
                   cout<<0;
                  for(int k=i;k<=n;k++)
                  {
                      if(dp[k][x])
                      {
                          cout<<1;
                          x+=a[k];
                      }
                      else cout<<0;
                  }
                  cout<<endl;
               break;
              }
        }
     if(flag==0)
             printf("No\n");
       
         
         
    }
}