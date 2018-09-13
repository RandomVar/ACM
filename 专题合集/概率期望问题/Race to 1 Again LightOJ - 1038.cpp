#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
double dp[maxn];

void getdp(int n)
{
  for(int i=2;i<=n;i++)
  {
    int cnt=0;
    double sum=0;
    for(int j=1;j*j<=i;j++)
    {
      if(i%j==0)
      {
        cnt++;
        sum+=dp[j];
       if(j*j!=i)
        sum+=dp[i/j],cnt++;
      }
      dp[i]=(sum+1.0*cnt)/double(cnt-1);
    }
  }
}


int main()
{
  int t;int cas=0;
  scanf("%d",&t);
  // getPrime();
  getdp(1e5);
  while(t--)
  {
     int n;
     scanf("%d",&n);

     printf("Case %d: %.7lf\n",++cas,dp[n]);
  }
}
