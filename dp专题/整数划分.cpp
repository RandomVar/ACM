//dp[i][j]=dp[i][j-1]*a[k+1][i] 
//到i放入第j个称号 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int dp[22][22];
int sum[22];
int main(){
	int t;cin>>t;
	while(t--){
		char a[22];int m;cin>>a;cin>>m;
		int len=strlen(a);
		dp[0][0]=1;
		sum[0]=a[0];
		for(int i=1;i<len;i++)
		 sum[i]=sum[i-1]+a[i]-'0';
        for(int i=0;i<len;i++)
          for(int j=1;j<=m;j++)
		 	for(int k=0;k<i;k++)
		 	 dp[i][j]=max(dp[i][j],dp[k][j-1]*(sum[i]-sum[k]));
		cout<<dp[len-1][m]<<endl;	
		 }	
	}

