#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e7+9;
ll a[1010];
ll dp[1010][1010];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;int cas=0;
  while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
   memset(dp,0,sizeof(dp));
   dp[1][1]=1;
   for(int i=2;i<=n;i++)
     {
         dp[i][1]=1;
         ll MAX=0;
        for(int k=i-1;k>=1;k--){
          if(a[k]>=MAX&&a[k]<a[i]) {
             for(int j=1;j<=m;j++)
                dp[i][j]=(dp[i][j]+dp[k][j-1]+dp[k][j])%mod;
            MAX=a[k];
            }
           }
     }
      ll ans=0;ll MAX=0;
    // for(int i=1;i<=n;i++)
      // cout<<dp[i][2]<<" ";
      cout<<"Case #"<<++cas<<": ";
      //ans+=dp[n][m];
     for(int k=n;k>=1;k--){
          if(a[k]>=MAX) {
                ans=(dp[k][m]+ans)%mod;
            MAX=a[k];
            }}

        cout<<ans<<endl;
//        cout<<dp[n][m]<<endl;
     }
  return 0;
  }

