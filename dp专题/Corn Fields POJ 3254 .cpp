/* 每一行总共2^N种状态，其中删去有相邻的状态，删除不符合给定条件的状态。
保留下最终的所有状态 */
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int MOD=100000000; 
int dp[1<<13][13];
int map[13][13];
int v[1<<13];
int m;
void init(){
  int cnt=0;
  for(int i=0;i<(1<<12);i++){
  	if((i&(i<<1))==0) v[cnt++]=i;
  }	
}

int check(int p,int j){
	for(int i=0;i<m;i++)
	  if((p&(1<<i))&&(!map[j][i]))
	   return 1;
	return 0;
}
int main(){
	int n;
	init();
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++)
		    cin>>map[i][j];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
		for(int j=0;v[j]<(1<<m);j++){
			if(check(v[j],i)) continue;
		   	if(i==0) {
			   dp[j][i]=1;continue;}
		 	for(int k=0;v[k]<(1<<m);k++)
		 		if((v[j]&v[k])==0) dp[j][i]=(dp[j][i]+dp[k][i-1])%MOD;
		 	 }}
	ll ans=0;
	for(int i=0;v[i]<(1<<m);i++)
	   ans=(ans+dp[i][n-1])%MOD;
	cout<<ans<<endl;
}}
