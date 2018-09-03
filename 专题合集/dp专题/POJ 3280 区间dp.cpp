#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
char s[2010]; 
int dp[2010][2010];
int cost[30];
int main(){
	int n,m;
	cin>>n>>m;
	cin>>s;
		for(int i=0;i<n;i++){
			char ch;int ac,bc;
			cin>>ch;cin>>ac>>bc;
			cost[ch-'a']=min(ac,bc); 
		}
		memset(dp,0,sizeof(dp));
		for(int i=m-1;i>=0;i--){
			for(int j=i+1;j<m;j++){
				  dp[i][j]=min(dp[i+1][j]+cost[s[i]-'a'],dp[i][j-1]+cost[s[j]-'a']);
				if(s[i]==s[j]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			}
		}
		cout<<dp[0][m-1]<<endl;
	}
