#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath> 
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int vis[1210],lowc[1210];
int cost[1210][1210];
void dij(int n){
	  memset(vis,0,sizeof(vis));
	  vis[1]=1;
	  int ans;
	   for(int i=1;i<=n;i++) lowc[i]=cost[1][i];
		for(int i=1;i<=n;i++){
			ans=0;int x;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&ans<lowc[j]){
					ans=lowc[j];x=j;
				}
			}
			vis[x]=1;
			for(int j=1;j<=n;j++){
				  lowc[j]=max(lowc[j],min(lowc[x],cost[x][j]));
			}
		}
		return ;
}
int main(){
	int t;scanf("%d",&t);int x=0;
	while(t--){
		x++;
		int n,m;scanf("%d%d",&n,&m);
       memset(cost,0,sizeof(cost));
		for(int i=1;i<=m;i++){
	        int a,b,c;
	        scanf("%d%d%d",&a,&b,&c);
		  if(c>0) {
		   cost[a][b]=c;
		  cost[b][a]=c;}
		  
     	}
	dij(n);
printf("Scenario #%d:\n%d\n\n", x, lowc[n]);}
return 0;}
