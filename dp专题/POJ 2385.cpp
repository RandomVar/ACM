#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int n[1010];
int dp[50][2];
int main(){
	int t,w;
	while(cin>>t>>w){
		for(int i=0;i<t;i++)
		  cin>>n[i];
		memset(dp,0,sizeof(dp));
		if(n[0]==2) dp[0][0]=1;
		else dp[1][1]=1;
		for(int i=0;i<t;i++){
		  for(int j=0;j<=w;j++){
		  	if(n[i]==2){
			  dp[j][1]=max(dp[j][1],dp[j+1][0])+1;} 
			else{
				dp[j][0]=max(dp[j][0],dp[j+1][1])+1;
			}}
			//cout<<dp[w][0]<<" "<<dp[w][1]<<endl;
		}
		int ans=-1;
		for(int j=0;j<=w;j++){
		  ans=max(ans,dp[j][0]);
		  ans=max(ans,dp[j][1]);}
		cout<<ans<<endl;
		  }
	}
