#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=6010;
vector<int>g[maxn];
int dp[maxn][2];
int par[maxn];
void dfs(int root){
	for(int i=0;i<g[root].size();i++)
	  dfs(g[root][i]);
	for(int i=0;i<g[root].size();i++)
	{
        dp[root][1]+=dp[g[root][i]][0];
		dp[root][0]+=max(0,max(dp[g[root][i]][0],dp[g[root][i]][1]));
	}


int main(){
	int n;
	while(cin>>n){
    for(int i=0;i<=n;i++)
    g[i].clear();
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	  cin>>dp[i][1];
	memset(par,-1,sizeof(par));
	while(1){
		int u,v;
		cin>>u>>v;
		if(u==0&&v==0) break;
		par[u]=v;
		g[v].push_back(u);
	}
	int root=1;
	while(par[root]!=-1) root=par[root];
	dfs(root);
	int ans=max(dp[root][0],dp[root][1]);
	printf("%d\n",ans);
}}
