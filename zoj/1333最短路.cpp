#include<cstdio>
#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=30;
int cost[maxn][maxn];
int vis[maxn];
int d[maxn];
double w[maxn];
double v[maxn];
void dij(){
	memset(vis,0,sizeof(vis));
	fill(d,d+maxn,INF);
	d[0]=0;
	while(1){
		int v=-1;
		for(int i=0;i<=26;i++){
			if(!vis[i]&&(v==-1||d[v]>d[i])) {
			v=i;
		}}
		if(v==-1) break;
		vis[v]=1;
		for(int i=0;i<=26;i++){
	          if(cost[i][v]==1) d[i]=min(d[i],d[v]+cost[i][v]);
		}
	}
} 
int main(){
	int n;
	while(cin>>n){
		memset(cost,0,sizeof(cost));
		fill(v,v+maxn,0);
		fill(w,w+maxn,0);
		getchar();
		int k=n;
		while(k--){
		char a;
		cin>>a;
		cin>>w[a-'A'+1];
		getchar();
		char b;
		while(1){
		  b=getchar();
		  if(b=='\n') break;
		  if(b=='*') cost[a-'A'+1][0]=1;
		  else cost[a-'A'+1][b-'A'+1]=1;
		}}
		dij();
		for(int i=1;i<=26;i++){
			v[i]=w[i]*(1-(d[i]-1)*0.05);
		}
		double max=0;int x;
		for(int i=1;i<=26;i++){
			if(max<v[i]) {
			max=v[i];x=i;
		}}
		char ans=x+'A'-1;
		printf("Import from %c\n",ans);
	}
}
