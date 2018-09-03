#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int vis[1010];
int lowc[1010];
int lowc2[1010];
int cost[1010][1010];
void dij1(int n,int x){
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	for(int i=1;i<=n;i++) lowc[i]=cost[x][i];
	for(int i=2;i<=n;i++){
		int y;int mmin=INF;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&mmin>lowc[j]) {
			  mmin=lowc[j]; y=j;}
		  }
		  vis[y]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&lowc[j]>cost[y][j]+lowc[y])
			  lowc[j]=cost[y][j]+lowc[y];
		}
	}
}
void dij2(int n,int x){
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	for(int i=1;i<=n;i++) lowc2[i]=cost[i][x];
	for(int i=2;i<=n;i++){
		int y;int mmin=INF;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&mmin>lowc2[j]) {
			  mmin=lowc2[j]; y=j;}
		  }
		  vis[y]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&lowc2[j]>cost[j][y]+lowc2[y])
			  lowc2[j]=cost[j][y]+lowc2[y];
		}
	}
}
int main(){
	int n,m,x;
	while(cin>>n>>m>>x){
		for(int i=1;i<=n;i++){
		  for(int j=1;j<=n;j++)
		    {cost[i][j]=INF;}
		    cost[i][i]=0;}
		    
		for(int i=1;i<=m;i++){
			int a,b,t;
			cin>>a>>b>>t;
			cost[a][b]=t;
		}
		dij1(n,x);
		dij2(n,x);
		int ans=0;
		
	for(int i=1;i<=n;i++)
	  ans=max(ans,lowc[i]+lowc2[i]);
	cout<<ans<<endl;
}}
