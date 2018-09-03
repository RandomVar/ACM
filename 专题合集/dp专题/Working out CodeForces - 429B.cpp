#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m){
      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          cin>>a[i][j];
      for(int i=1;i<=n;i++)
        for(int j=1;j<=(m+1)/2;j++){
           if(j==(m+1)/2&&dp1[i][j-1]<dp1[i-1][j]-qu[i-1]){
               dp1[i][j]=dp1[i-1][j]+a[i][j];
               qu[i]=qu[i-1]+a[i][j];
           }
           else if(j==(m+1)/2){
              dp1[i][j]=dp1[i][j-1];
              qu[i]=a[i][j];
           }
            else dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
        }

      for(int i=n;i>=1;i--)
        for(int j=1;j<=(m+1)/2;j++)
            dp2[i][j]=max(dp2[i][j-1],dp2[i+1][j])+a[i][j];
       for(int i=n;i>=1;i--)
        for(int j=m;j>=(m+1)/2;j--)
            dp3[i][j]=max(dp3[i+1][j],dp3[i][j+1])+a[i][j];
        for(int i=1;i<=n;i++)
          for(int j=m;j>=1;j--)
            dp4[i][j]=max(dp4[i][j+1],dp4[i-1][j])+a[i][j];
         for(int i=1;i<=n;i++){
              ans[i]=max(dp1[i][(m+1)/2-1]+dp2[i][(m+1)/2-1]+dp3[][])
         }

  }

}
