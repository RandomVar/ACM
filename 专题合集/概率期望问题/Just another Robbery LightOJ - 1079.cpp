#include<bits/stdc++.h>
using namespace std;
struct node{
  int m;double p;
}a[200];
double dp[10100];
int main()
{
  #ifndef ONLINE_JUDGE
      freopen("data.in","r",stdin);
       freopen("data.out","w",stdout);
      #endif
  int t;int cas=0;
  scanf("%d",&t);
  while(t--)
  {
    double p;
    int n;int tot=0;
    scanf("%lf%d",&p,&n);
    for(int i=1;i<=n;i++)
     {
       scanf("%d%lf",&a[i].m,&a[i].p);
       tot+=a[i].m;
     }
    //  cout<<tot<<endl;
   for(int s=1;s<=tot;s++)
     dp[s]=1.0;
     dp[0]=0;

    for(int i=1;i<=n;i++)
      for(int s=tot;s>=a[i].m;s--)
      {
        dp[s]=min(dp[s],dp[s-a[i].m]+a[i].p-dp[s-a[i].m]*a[i].p);
        // cout<<dp[s]<<" "<<dp[s-a[i].m]<<" "<<a[i].p<<endl;
      }
      int ans=0;
      for(int s=tot;s>=0;s--)
      {
        if(dp[s]<p) ans=max(ans,s);
      }
    printf("Case %d: %d\n",++cas,ans);
  }
}
