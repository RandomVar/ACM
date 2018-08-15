#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[110][110];
int c[110],v[110];
int MAX(int a,int b,int c){
return max(max(a,b),c);}
int main(){
  int n,t;
  while(cin>>n>>t){
        for(int i=0;i<=t;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        int m,s;
        cin>>m>>s;
        for(int j=0;j<m;j++)
            cin>>c[j]>>v[j];
        if(s==0){
            for(int u=t;u>=0;u--) dp[i][u]=-INF;
            for(int j=0;j<m;j++)
              for(int u=t;u>=c[j];u--){
                dp[i][u]=MAX(dp[i][u],dp[i-1][u-c[j]]+v[j],dp[i][u-c[j]]+v[j]);
            }
        }
        if(s==1){
            for(int u=t;u>=0;u--) dp[i][u]=dp[i-1][u];
            for(int j=0;j<m;j++)
                for(int u=t;u>=c[j];u--)
                  dp[i][u]=max(dp[i][u],dp[i-1][u-c[j]]+v[j]);
        }
        if(s==2){
            for(int u=t;u>=0;u--) dp[i][u]=dp[i-1][u];
            for(int j=0;j<m;j++)
                for(int u=t;u>=c[j];u--)
                  dp[i][u]=MAX(dp[i][u],dp[i-1][u-c[j]]+v[j],dp[i][u-c[j]]+v[j]);
        }

    }
    if(dp[n][t]>0)
      cout<<dp[n][t]<<endl;
    else cout<<-1<<endl;
  }
}
