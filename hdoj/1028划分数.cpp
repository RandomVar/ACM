/*dp[i][j]=dp[i-j][j]+dp[i][j-1]*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int dp[150][150]; 
int main(){
	int n;
	while(cin>>n){
		 for(int i=0;i<=n;i++)
		   dp[i][0]=0; 
		   dp[0][0]=1;  
		for(int i=0;i<=n;i++)
		 for(int j=1;j<=n;j++){
		 	if(i>=j) dp[i][j]=dp[i-j][j]+dp[i][j-1];
		 	else dp[i][j]=dp[i][j-1];
		 };
		   cout<<dp[n][n]<<endl;
	}
}
