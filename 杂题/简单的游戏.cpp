#include<bits/stdc++.h>
using namespace std;

int ini[10][10]={
0,0,1,1,0,1,0,1,0,0,
0,1,1,0,1,0,1,0,0,0,
1,1,0,1,0,1,0,0,0,1,
1,0,1,0,1,0,0,0,1,0,
0,1,0,1,0,0,0,1,0,1,
1,0,1,0,0,0,1,0,1,0,
0,1,0,0,0,1,0,1,0,0,
1,0,0,0,1,0,1,0,0,0,
0,0,0,1,0,1,0,0,0,1,
0,0,1,0,1,0,0,0,1,0
};
vector<int>v[8];
char s[8][8];
int n,m;
int cnt;
vector<int>vec;
const int maxn=1e7+10;
int dp[2][maxn];
int f;
void isok(int x,int y,int st)
{
    if(y==m) 
    {
     v[x].push_back(st);
     return;
    }
    int pre=st%10;
    // cout<<x<<" "<<y<<" "<<st<<endl;
    if(s[x][y]=='?')
    {
        if(y==0)
        {
            for(int i=0;i<10;i++)
             isok(x,y+1,i);
        }
        for(int i=0;i<10;i++)
         if(ini[pre][i]==1)
        {
           int news=st*10+i;
           isok(x,y+1,news);
        }
    }
    else
    {
        int flag=0;
        int c=s[x][y]-'0'; 
       isok(x,y+1,st*10+c);
    }
}
// void inidfs(int x,int pre,int st)
// {
//     if(x==m)
//     {
//         ji[st]=1;
//         //vec.push_back(st);
//         return;
//     }
//     for(int i=0;i<9;i++)
//       if(x==0||ini[pre][i]+i)
//         inidfs(x+1,i,st*10+i);
// }
void solve(int x,int pres)
{
    for(int i=0;i<v[x].size();i++)
    {
        int flag=1;
        int c=v[x][i];
    for(int j=0;j<m;j++)
    {
        if(ini[pres%10][c%10]==0)
           {
               flag=0;
           }
           pres/=10;c/=10;
    }
          if(flag) 
          {
              dp[f][pres]+=dp[f^1][pres];
          }
    }
}/*
void dfs(int x,int pres)
{
    if(x==n)
    {
        cnt++;
        return;
    }
  for(int i=0;i<v[x].size();i++)
  {
      int c=v[x][i];
      int flag=1;
      for(int j=0;j<m;j++)
      {
          if(ini[pres%10][c%10]==0)
             {flag=0;break;}
        pres/=10;c/=10;
      }
      if(flag)
         dfs(x+1,v[x][i]);
  }
}*/
int main()
{
   while(scanf("%d%d",&n,&m)==2)
   {
   //    memset(ji,0,sizeof(ji));
     //  inidfs(0,0,0);
    //    for(int i=0;i<n;i++)
    //     scanf("%s",s[i]);
    //     for(int i=0;i<n;i++)
    //      dfs(i);
        
    //    cout<<vec.size()<<endl;
    //    cout<<cnt<<endl;
      for(int i=0;i<n;i++)
        v[i].clear();
       int flag=1;
       for(int i=0;i<n;i++)
        scanf("%s",s[i]);
        for(int i=0;i<n;i++)
         isok(i,0,0);
     for(int i=0;i<n;i++)
      cout<<v[i].size()<<endl;
     int ans=0;
     f=0;
     memset(dp,0,sizeof(dp));
     for(int i=0;i<v[0].size();i++)
      dp[f^1][v[0][i]]=1;
     for(int i=0;i<n-1;i++)
     {
      for(int j=0;j<v[i].size();j++)
         solve(i+1,v[i][j]);
       f^=1;
     }
     for(int i=0;i<v[n].size();i++)
       ans+=dp[n][i];
     printf("%d\n",ans);
   }
}