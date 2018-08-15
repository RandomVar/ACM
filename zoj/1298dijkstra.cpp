#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=505;
int cost[maxn][maxn];
int vist[maxn];
int lowc[maxn];
void dijkstra(int n){
	for(int i=1;i<=n;i++) vist[i]=0;
	vist[1]=1;
	lowc[1]=0;
	for(int i=2;i<=n;i++) lowc[i]=cost[1][i];
	for(int i=2;i<=n;i++){
		int x;int min=INF;
		for(int j=2;j<=n;j++) {
			if(!vist[j]&&min>lowc[j]) {
			min=lowc[j];x=j;
		}}
		vist[x]=1;
		for(int j=2;j<=n;j++){
			if(!vist[j]&&lowc[x]+cost[x][j]<lowc[j]) {
			lowc[j]=lowc[x]+cost[x][j];
		}
	}
}}
int main(){
	int n,m;int k=0;
	while(cin>>n>>m&&(n+m)!=0){
		k++;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    {cost[i][j]=INF;}
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			cin>>cost[u][v];
			cost[v][u]=cost[u][v];
		}
		dijkstra(n);
		double ans=-1;int x,y,d;int flag=0;
		for(int i=2;i<=n;i++)
		     if(ans<lowc[i]) {ans=lowc[i];d=i;}
		for(int i=1;i<=n;i++)
		  for(int j=2;j<=n;j++)
		    if(cost[i][j]!=INF&&(abs)(lowc[i]-lowc[j])!=cost[i][j]&&(double)(lowc[i]+lowc[j]+cost[i][j])/2>ans){
		       ans=(double)(lowc[i]+lowc[j]+cost[i][j])/2;x=i;y=j;flag=1;
	}
	printf("System #%d\n",k);
	if(flag==0)
	 printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",ans,d);
	else 
	  printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",ans,x,y);
	}
}

