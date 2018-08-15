#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
const int maxn=105;
int cost[maxn][maxn];
int vist[maxn];
int lowc[maxn];
void dij(int n){
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
			if(lowc[x]+cost[x][j]<lowc[j]) lowc[j]=lowc[x]+cost[x][j];
		}
	}
}
int main(){
	int n;
	while(cin>>n){
		memset(cost,0,sizeof(cost));
		for(int i=2;i<=n;i++){
		  for(int j=1;j<i;j++){
		  	char t[10];cin>>t;
		  	if(t[0]!='x') {
		  		sscanf(t,"%d",&cost[i][j]);//注意这里的输入方法 
				cost[j][i]=cost[i][j];}
			else {
				cost[i][j]=INF;
				cost[j][i]=INF;
			}
		  }}
	dij(n);
	int ans=0;
	for(int i=1;i<=n;i++){
	  ans=max(ans,lowc[i]);}
	cout<<ans<<endl;	
}}
