#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[5010][5010];
int a[5010];
int main(){
   int n;
   while(cin>>n){
    for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        dp[i][1]=a[i]=t;
   }
   for(int j=2;j<=n;j++)
    for(int i=1;j+i<=n+1;i++){
       dp[i][j]=(dp[i][j-1]^dp[i+1][j-1]);
       ans[i][j]=max(ans[i][j-1],max(ans[i-1][j+1],dp[i][j]));
    }
   int q;
   cin>>q;
   for(int i=0;i<q;i++){
      int l,r;
      cin>>l,r;
      cout<<dp[l][r]<<endl;

   }
}
