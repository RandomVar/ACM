#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int s[110];
int dp[110][110];
int main(){
	int t;cin>>t;int a=0;
	while(t--){
		a++;
		int len;cin>>len;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;i++){
		  cin>>s[i];
		}
	/*	for(int i=0;i<=len;i++)
		  for(int j=i;j<=len;j++){
		  	dp[i][j]=j-i+1;
		  }*/
		  
		for(int i=len-1;i>=0;i--){
		    dp[i][i]=1;
			for(int j=i+1;j<len;j++){
			dp[i][j]=INF;	
			  if(s[j]==s[i]) dp[i][j]=dp[i][j-1];		
				for(int k=i;k<j;k++){     //这边必须从i开始，才能做相当于初始化的工作  	
				  if(s[i]==s[k]) 
				      dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}}
	}
     printf("Case %d: %d\n",a,dp[0][len-1]);
}
return 0;
} 
