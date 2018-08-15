#include<bits/stdc++.h>
using namespace std;
int dp[20010];
int a[40];
int main(){
  int v,n;
  while(cin>>v>>n){
    for(int i=0;i<n;i++)
        cin>>a[i];
        int ans=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
    for(int i=0;i<n;i++)
      for(int j=v;j>=a[i];j--){
        if(dp[j-a[i]]) {ans=max(ans,j);dp[j]=1;}
    }
    cout<<v-ans<<endl;
  }
}
