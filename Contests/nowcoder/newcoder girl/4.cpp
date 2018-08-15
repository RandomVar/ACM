#include <iostream>
#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1110][1<<11];
int a[11];
int main(){
   int n,s;
   cin>>n>>s;
   int ma=0;
   for(int i=0;i<n;i++){
     cin>>a[i];
     //ma=max(ma,a[i]);
     }
     sort(a,a+n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=s+ma;j>=0;j--)
          for(int k=0;k<(1<<n);k++){
              dp[j][k]=max(dp[j][k],dp[j-a[i]][k&(1<<i)]+1);
    }

    int ans=0;
    for(int i=s;i<=s+ma;i++)
      for(int k=0;k<(1<<n);k++){
        if(dp[i][k]>ans){
            int flag=0;
            for(int j=0;j<n;j++)
            if(k&(1<<(n-1-j))) {
                if(dp[i][k]-a[j]<s) {
                    flag=1;break;
                }
            }
         if(flag) ans=dp[i][k];
        }
      }
      cout<<ans<<endl;}
   /*for(int i=0;i<n;i++)
    for(int j=s+ma;j>=0;j--){
        for(int k=0;k<n;k++){
            if(dp[j-a[i]][k]!=-1){
            if(j-a[k]<s&&a[i]>=a[k]){
                 dp[j][k]=max(dp[j][k],dp[j-a[i]][k]+1);
             }
           else if(a[i]<a[k]&&j-a[i]<s){
                dp[j][i]=max(dp[j][i],dp[j-a[i]][k]+1);
            }
           }}}
    int ans=0;
    for(int i=s;i<=s+ma;i++)
        for(int k=0;k<n;k++){
         if(ans<dp[i][k]) cout<<dp[i][k]<<" "<<i<<" "<<k<<endl;
          ans=max(ans,dp[i][k]);}
    cout<<ans<<endl;
    cout<<dp[12][2]<<endl;
}*/
/*
5 9
4 1 3 5 4
*/
