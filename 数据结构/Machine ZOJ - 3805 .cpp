#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int>v[maxn];
int dp[maxn];
void dfs(int u){
	int len=v[u].size();
	if(len==0) dp[u]=1;
	if(len==1) {
		dfs(v[u][0]);
		dp[u]=dp[v[u][0]];
	}
	if(len==2){
		dfs(v[u][0]);
		dfs(v[u][1]);
		int l=dp[v[u][0]];
		int r=dp[v[u][1]];
		if(l==r){
			dp[u]=l+1;
		}
		else{
			dp[u]=max(l,r);
		}
	}
}
int main(){
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<maxn;i++){
			v[i].clear();
		}
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			v[x].push_back(i);
		}
		dfs(1);
		cout<<dp[1]<<endl;
	}
	return 0;
} 
