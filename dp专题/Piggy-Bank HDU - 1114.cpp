#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[10010];
int v[550];
int w[550];
int main(){
  int t;cin>>t;
  while(t--){
  int x,y;
  cin>>x>>y;
    int n;cin>>n;
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<n;i++)
      cin>>v[i]>>w[i];
    dp[0]=0;
   for(int i=0;i<n;i++)
    for(int s=w[i];s<=y-x;s++)
        dp[s]=min(dp[s],dp[s-w[i]]+v[i]);
  if(dp[y-x]==INF) cout<<"This is impossible."<<endl;
  else
    cout<<"The minimum amount of money in the piggy-bank is "<<dp[y-x]<<"."<<endl;
}}
