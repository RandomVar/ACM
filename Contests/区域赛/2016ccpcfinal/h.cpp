#include<bits/stdc++.h>
using namespace std;
struct node{
    int c;
     int cc[5];
}a[15];
struct node2{
    int c;
    int cc[5];
}b[15];
int dp[12][1<<12];
int vis[110];
vector<int> can[12];
vector<int>vec;
int main(){
    int t;int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].c);
            for(int j=0;j<a[i].c;j++)
             scanf("%d",&a[i].cc[j]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i].c);
            for(int j=0;j<b[i].c;j++)
             scanf("%d",&b[i].cc[j]);
        }

        for(int i=0;i<=n;i++)
         for(int j=0;j<(1<<m);j++)
          dp[i][j]=0;
        // memset(dp,0,sizeof(dp));
       


       for(int i=1;i<=n;i++)
      {
          can[i].clear();
          for(int j=0;j<(1<<m);j++)
          {
              vec.clear();int flag=1;
               for(int w=0;w<m;w++)
               {
                    if(((1<<w)&j))
                        vec.push_back(w);
               }

                for(int w=0;w<a[i].c;w++)
               {
                     vis[a[i].cc[w]]=0;
                    //    flag=0;
               }

              for(int w=0;w<vec.size();w++)
               {
                   int u=vec[w];
                 for(int v=0;v<b[u].c;v++)
                     vis[b[u].cc[v]]=1;
               }

               for(int w=0;w<a[i].c;w++)
               {
                    if(!vis[a[i].cc[w]])
                       flag=0;
               }
               if(flag)
                 can[i].push_back(j);
            
           }
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(1<<m);j++)
             {
                 dp[i][j]=max(dp[i][j],dp[i-1][j]);
                 for(int x=0;x<can[i].size();x++)
                 {
                     int s=can[i][x];
                     vec.clear();
                      if(j&s) continue;
                    int yyy=j;
                    yyy|=s;
                    dp[i][yyy]=max(dp[i][yyy],dp[i-1][j]+1);
    
                 }
             }
        }
        int ans=0;
        for(int j=0;j<(1<<m);j++)
         ans=max(ans,dp[n][j]);
         printf("Case #%d: %d\n",++cas,ans);

    }
}