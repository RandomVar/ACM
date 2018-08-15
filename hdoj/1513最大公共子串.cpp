#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
char str[5010];
int pre[5010]; 
int dp[5010];
char a[5010];
int main(){
	int n;
	while(cin>>n){
		getchar();
		scanf("%s",str);
		int k=0;
		for(int i=n-1;i>=0;i--)
		 a[k++]=str[i];
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		for(int i=0;i<n;i++){
		  for(int j=0;j<n;j++){
			if(a[j]==str[i]) dp[j+1]=pre[j]+1;
			else dp[j+1]=max(pre[j+1],dp[j]);
			pre[j]=dp[j];
		}
		pre[n]=dp[n];}
		int t=n-dp[n]; 
	   cout<<t<<endl;
		}
	}
