#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int dp[100][100];
int f[100][100][5];
vector<char>v;
map<string,int>mp;
int cnt;
map<string,int>::iterator it;
void dfs(int x,int y)
{
    if(x==0||y==0)
      {
           int c=v.size();
           string s;
           for(int i=c-1;i>=0;i--)
             s+=v[i];
             mp[s]=1;
            //cout<<v[i];
       return;
       }
    if(dp[x-1][y]==dp[x][y])
     dfs(x-1,y);
     if(dp[x][y-1]==dp[x][y])
     dfs(x,y-1);
     if(dp[x-1][y-1]+1==dp[x][y]&&a[x]==b[y])
    {
        v.push_back(a[x]);
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
    //   for(int i=1;i<=m;i++)
    //    cout<<a[i];
    //    cout<<endl;
    //    for(int i=1;i<=n;i++)
    //     cout<<b[i];
    //     cout<<endl;
     for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
      {
          
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        // if(a[i]==b[j]&&dp[i-1][j-1]+1>=dp[i][j])
        //   dp[i][j]=dp[i-1][j-1],f[i][j]=1;
        if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);       
      }
      for(int i=1;i<=m;i++)
      {
       for(int j=1;j<=n;j++)
       {
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
      }
      printf("Case %d\n%d\n",++cas,dp[m][n]);
      cnt=0;
       dfs(m,n);
       for(it=mp.begin();it!=mp.end();it++)
       {
           cout<<it->first<<endl;
       }
       printf("%d\n",mp.size());
    }
}


