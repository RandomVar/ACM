#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=609929123;
ll dp[2010][4];
ll a[2010];
int main(){
  int m;
  while(cin>>m){
        memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
      dp[i][1]=(dp[i-1][1]+a[i])%MOD;
    for(int j=2;j<=3;j++)
      for(int i=j;i<=m;i++)
        dp[i][j]=(dp[i-1][j]+(dp[i-1][j-1]*a[i])%MOD)%MOD;
      cout<<dp[m][3]<<endl;
    /*ll cnt=0;ll ans;
    for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                ans=((x[i]*x[j])%MOD)*x[k]%MOD;
                cnt=(cnt+ans)%MOD;
            }
        }
    }
    cout<<cnt<<endl;*/
  }
}
