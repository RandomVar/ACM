#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int c[110];
int v[110];
int dp[110][110];
int main(){
  int n,m,k,s;
  while(cin>>n>>m>>k>>s){
    for(int i=0;i<k;i++)
        cin>>v[i]>>c[i];

    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++)
      for(int j=c[i];j<=m;j++){
       for(int t=0;t<s;t++) {
            dp[j][t+1]=max(dp[j][t+1],dp[j-c[i]][t]+v[i]);
    }
  }
  int ma=-1;
 for(int j=0;j<=m;j++){
   for(int t=0;t<=s;t++)
 {
   if(dp[j][t]>=n){
    ma=m-j;
    break;
   }
 }
   if(ma!=-1) break;}
  cout<<ma<<endl;
}}
