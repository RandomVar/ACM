#include<bits/stdc++.h>
using namespace std;
char yuan[]={'a','e','i','o','u'};
int isyuan(char c)
{
  for(int i=0;i<5;i++)
  {
    if(c==yuan[i])
     return 1;
  }
  return 0;
}
int x,y;
const int maxn=1e6+100;
char s[maxn];
int dp[maxn][2];
int check()
{
  int len=strlen(s);
  dp[0][0]=dp[0][1]=0;
for(int i=1;i<=len;i++)
{
  if(s[i-1]=='?')
  {
    if(dp[i-1][1]<x)
    {
      dp[i][1]=dp[i-1][1]+1;
      dp[i][0]=1;
    }
    if(dp[i-1][0]<y)
    {
      dp[i][0]=min(dp[i][0],dp[i-1][0]+1);
      dp[i][1]=1;
    }
  }
  else if(s[i-1]=='1')
  {
    if(dp[i-1][1]<x)
       dp[i][1]=dp[i-1][1]+1;
      if(dp[i-1][0]<y)
         dp[i][1]=1;
  }
  else if(s[i-1]=='0')
  {
    if(dp[i-1][0]<y)
      dp[i][0]=dp[i-1][0]+1;
    if(dp[i-1][1]<x)
      dp[i][0]=1;
  }
    if(dp[i][1]>=x&&dp[i][0]>=y) return 0;
}
return 1;
}
int main()
{
  int t;
  scanf("%d",&t);
  int cas=0;
  while(t--)
  {
    memset(dp,0x3f,sizeof(dp));
    scanf("%s",s);
    scanf("%d%d",&x,&y);
    int f1=0;int f2=0;
    int len=strlen(s);
    int maa=0;int mab=0;
    int sa=0;int sb=0;
    for(int i=0;i<len;i++)
    {
      if(isyuan(s[i]))
      {
        s[i]='1';
        sa++;
        maa=max(sa,maa);
        sb=0;
      }
      else if(s[i]!='?')
      {
        s[i]='0';
        sb++;
        sa=0;
        mab=max(sb,mab);
      }
      else if(s[i]=='?')
      {
        sa++;
        sb++;
        maa=max(maa,sa);
        mab=max(mab,sb);
      }
    }
    if(maa>=x||mab>=y)
      f1=1;
    if(check()) f2=1;
    printf("Case #%d: ",++cas);
    if(f1&&f2)
     printf("SURPRISE\n");
    else if(f1)
      printf("DISLIKE\n");
    else if(f2)
     printf("LIKE\n");

  }
}
