#include<bits/stdc++.h>
using namespace std;
const int maxn=6010;
vector<int>v[maxn];
int dp[maxn][2];

int main(){
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		  cin>>dp[i][1];
		int x,y;
		while(cin>>x>>y){
			if(x==0&&y==0) break;
			if(x<y) v[y].push_back(x);
			else v[x].push_back(y);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		  for(int j=0;j<v[i].size();j++){
		  	if(vis[j])
		  	dp[i][0]+=dp[v[i][j]][1];
		  	dp[i][1]+=dp[v[i][j]][0];
		  }
		cout<<max(dp[n][0],dp[n][1])<<endl;
		}
	}
