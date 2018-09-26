#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[30][30];
int ji[30][5];
int f[30][30];
int p[30];
void dfs(int s,int t)
{
   if(s>=t) return;
   if(f[s][t]==-1) return;
    ji[s][1]++;
//    ji[f[s][t]][2]=1;
//    ji[f[s][t]][1]=1;
    ji[t][2]++;
    // cout<<s<<" "<<t<<endl;
   dfs(s,f[s][t]);
   dfs(f[s][t],t);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;int cas=0;
    while(cin>>n)
    {
        memset(ji,0,sizeof(ji));
        memset(dp,0x3f,sizeof(dp));
        memset(f,-1,sizeof(f));
       for(int i=0;i<=n;i++)
       {
           cin>>p[i];
          dp[i][i+1]=0;
       }
       for(int len=1;len<=n;len++)
       {
         for(int i=1;i<=n;i++)
         {
             int j=i+len;
             if(j>n) break;
            for(int k=i;k<j;k++)
            {
                if(dp[i-1][j]>dp[i-1][k]+dp[k][j]+1LL*p[k]*p[i-1]*p[j])
                {
                    dp[i-1][j]=dp[i-1][k]+dp[k][j]+1LL*p[k]*p[i-1]*p[j];
                    f[i-1][j]=k;
                //   cout<<i-1<<" "<<j<<" "<<dp[i-1][j]<<endl;
                }
            }
         }
       }
       dfs(0,n);
       cout<<"Case "<<++cas<<endl;
      cout<<dp[0][n]<<" ";
     ji[0][1]--;
     ji[n][2]--;
    while(ji[0][1]>0) 
    {
        cout<<"(";
        ji[0][1]--;
    }
      for(int i=1;i<=n;i++)
      {
         cout<<"A"<<i;
        while(ji[i][2]>0)
          {
              cout<<")";
             ji[i][2]--;
          }
        while(ji[i][1]>0)
            {
                cout<<"(";
                   ji[i][1]--;
            }
      }
      cout<<endl;
       

    }

}