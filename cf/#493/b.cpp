#include<bits/stdc++.h>
using namespace std;
int a[110];
int v[110];
int dp[110];
int main()
{
    int n,b;
    while(cin>>n>>b)
    {
         int cnt=0;
        for(int i=1;i<=n;i++)
         {cin>>a[i];if(a[i]%2) cnt++;}
         if(2*cnt!=n)
         {
           cout<<0<<endl;
          continue;
         }
        cnt=0;
         int k=0;
         for(int i=1;i<=n;i++)
         {
             if(a[i]%2) cnt++;
             if(2*cnt==i&&i<n)
             {
                 v[++k]=abs(a[i]-a[i+1]);
             }
         }
         int ans=0;
         memset(dp,0,sizeof(dp));
         for(int i=1;i<=k;i++)
            for(int j=b;j>=v[i];j--)
            {
                dp[j]=max(dp[j],dp[j-v[i]]+1);
                 ans=max(ans,dp[j]);
            }
            printf("%d\n",ans);
    }
}