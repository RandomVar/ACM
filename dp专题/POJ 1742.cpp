/*多重背包可行性*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int a[110];
int c[110];
int dp[100010];
int sum[100010];
int main(){
	int n,m;
	while(cin>>n>>m&&(n+m)!=0){
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		for(int i=1;i<=n;i++)
		  cin>>c[i];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
		  memset(sum,0,sizeof(sum));
		  for(int j=a[i];j<=m;j++){
		  	if(!dp[j]&&dp[j-a[i]]&&sum[j-a[i]]<c[i]){
		  	dp[j]=1;
		  	sum[j]=sum[j-a[i]]+1;
		  	cnt++;
		  }}}
		cout<<cnt<<endl;
	}
}
