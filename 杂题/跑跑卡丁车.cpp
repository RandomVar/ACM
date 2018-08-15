#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[200];
int b[200];
int dp[11000][20];
int main(){
  int l,n;
  while(cin>>l>>n){
        memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<l;i++)
        cin>>a[i];
    for(int i=0;i<l;i++)
        cin>>b[i];
    dp[0][1]=a[0];
    for(int i=1;i<l*n;i++){
        for(int k=0;k<=10;k++){
          if(k>=5) dp[i][k-5]=min(dp[i][k-5],dp[i-1][k]+b[i%l]);
          if(k<=9) dp[i][k+1]=min(dp[i][k+1],dp[i-1][k]+a[i%l]);
          else dp[i][10]=min(dp[i][10],dp[i-1][10]+a[i%l]);
         cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
    }}
    int ans=INF;
   // cout<<dp[0][1]<<" "<<a[1%18]<<" "<<dp[1][2]<<endl;
   for(int i=0;i<=10;i++)
      ans=min(ans,dp[l*n-1][i]);

  cout<<ans<<endl;
}}
