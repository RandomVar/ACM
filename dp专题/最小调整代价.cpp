#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[110][110];
int a[110];
int main(){
  int n,s;
  while(cin>>n>>s){
  int mi=INF;int ma=-INF;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(mi>a[i]) mi=a[i];
    if(ma<a[i]) ma=a[i];
  }
  int MIN=INF;
  memset(dp,0x3f,sizeof(dp));
  for(int i=0;i<=n;i++){
    for(int j=mi;j<=ma;j++){
        if(i==0){
            dp[0][j]=0;continue;
        }
            int t;
        if(a[i]<=j+s&&a[i]>=j-s) t=0;
         else {
               t=min(abs(a[i]-j-s),abs(a[i]-j+s));
            }
        dp[i][j]=min(dp[i][j],dp[i-1][j]+t);
        if(i==n&&MIN>dp[n][j]) MIN=dp[n][j];
    }
  }
  cout<<MIN<<endl;
}
}
