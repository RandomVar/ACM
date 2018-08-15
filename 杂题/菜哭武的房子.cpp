#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
        memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
      for(int j=0;j<m;j++)
        if(s[i][j]=='1') {dp[i][j]=max(dp[i-1][j]+1,dp[i][j-1]);}
         else  dp[i][j]=dp[i-1][j];
  }
return 0;
}
