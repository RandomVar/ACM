#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=10010;
struct node{
	int x,w;
};
vector<node>g[maxn];
ll dp[maxn][3];
void dfs1(int root){
	for(int i=0;i<g[root].size();i++)
	{
		int x=g[root][i].x;
		dfs1(x);
		ll cost=dp[x][0]+g[root][i].w;
		if(cost>=dp[root][0]){
			swap(cost,dp[root][0]);
			dp[root][1]=cost;
		}
		else if(cost>dp[root][1]){
			dp[root][1]=cost;
		}
	}
}
void dfs2(int root){
	for(int i=0;i<g[root].size();i++){
		int x=g[root][i].x;
		ll w=g[root][i].w;
		dp[x][2]=max(dp[root][2],dp[x][0]+w==dp[root][0]?dp[root][1]:dp[root][0])+w;
		dfs2(x);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
	memset(dp,0,sizeof(dp)); 
	for(int i=2;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back((node){i,y});
	   }
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++)
      printf("%lld\n",max(dp[i][0],dp[i][2]));
    for(int i=1;i<=n;i++)  
        g[i].clear();
}}
