#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int dp[110][110];
int a[110]; 
int main(){
	int t;cin>>t; 
	while(t--){
		int n;cin>>n;
        for(int i=0;i<n;i++)
          cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(int i=n-2;i>=0;i--){
			for(int j=i+1;j<n;j++){
				dp[i][j]=dp[i+1][j];
			  for(int k=i+1;k<=j;k++){
			  	if(a[i]==a[k])
			  	dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k+1][j]+2);
			  }
			}
		}
		cout<<n-dp[0][n-1]/2<<endl;
	}
} 

