/*
　这道题的关键有两点：一是将smartness看作花费、将funness看作价值，
从而转化为01背包；二是对负值的处理，引入一个shift来表示“0”，这
里的shift一定要大于每一个smartness的绝对值，另
外在遍历cost[]的时候如果cost[i]>0，显然时从开的数组的最大值maxm 开始往下减，
如果cost[i]<0，则是从0（是0，不是shift）开始往上增加。大
于0的情况容易想到，小于0的情况比较费解，需要仔细思考。
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2e5+2e4;
const int shitf=1e4+10;
int s[110];
int f[110]; 
int dp[maxn+10];
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
		  cin>>s[i]>>f[i];
		fill(dp,dp+maxn,-INF);
		dp[shitf]=0;
		for(int i=1;i<=n;i++){
			if(s[i]>0){
		     for(int j=maxn-1;j>=s[i];j--)
		       dp[j]=max(dp[j],dp[j-s[i]]+f[i]);}
		    else{
		    	for(int j=0;j<maxn+s[i];j++)
		    	  dp[j]=max(dp[j],dp[j-s[i]]+f[i]);}
			}
		int ans=0;
		for(int i=shitf;i<maxn;i++){
			if(dp[i]>0) ans=max(ans,i-shitf+dp[i]);
		}
		cout<<ans<<endl;    
	}
}
