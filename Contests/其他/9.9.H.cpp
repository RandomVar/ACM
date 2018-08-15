#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int n; 
int cost[10010][10010];
int d[10010];
int dfs(int x){
	if(d[x]) return d[x];
	for(int i=1;i<=n;i++){
		if(cost[x][i]!=-1) d[x]=max(d[x],cost[x][i]+dfs(i));
	}
	return d[x];
}
int main(){
	int t;cin>>t;
	while(t--){
		int m;
		cin>>n>>m;
		memset(cost,-1,sizeof(cost));
		memset(d,0,sizeof(d));
		for(int i=1;i<=m;i++){
			int s,t,l;
			cin>>s>>t>>l;
			cost[s][t]=l;
	  }
	  int ans=0;
	  for(int i=1;i<=n;i++){
	  	 ans=max(ans,dfs(i));
	  }
	  cout<<ans<<endl;
}} 
