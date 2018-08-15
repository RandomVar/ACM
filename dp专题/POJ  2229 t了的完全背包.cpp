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
ll f[19];
void quick(){
	f[0]=1;
  for(int i=1;i<=19;i++)
    f[i]=2*f[i-1];
} 
void init(){
	memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<=19;i++){
			if(f[i]>1000100) break;
		  for(ll j=f[i];j<=1000100;j++){
		    dp[j]=(dp[j-f[i]]+dp[j])%mod;
		  }}
}
int main(){
	ll n;
	quick();
	init();
	while(scanf("%lld",&n)==1){
		printf("%lld\n",dp[n]);
	}
}
