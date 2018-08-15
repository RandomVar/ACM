#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const ll mod=1000000000;
ll dp[1000100]; 
int main(){
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int ans=0;
		for(int i=1;i<=n;i++){
		  if(i&1) dp[i]=dp[i-1];
		  else dp[i]=(dp[i-2]+dp[i/2])%mod;
		  }
		cout<<dp[n]<<endl;
	}
}
