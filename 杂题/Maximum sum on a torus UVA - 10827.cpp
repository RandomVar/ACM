#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;cin>>t;
   while(t--){
        int n,m;
       cin>>n>>m;
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          cin>>dp[i][j];
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(j==0)
             else dp[i][j]+=dp[i][j-1]+dp[i-1][j];

         }

     }


   }


}
