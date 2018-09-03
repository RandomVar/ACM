#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105];
int dp[105][105];
const int INF=0x3f3f3f3f;
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(int l=2;l<=n;l++)
		 for(int i=2;i+l-1<=n;i++)
		   {
		   	int j=i+l-1;
		   	dp[i][j]=INF;
		   	for(int k=i;k<=j-1;k++)
			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
		   }
		cout<<dp[2][n]<<endl;
	}
}
