#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const double INF=1e30; 
struct node{
	int x,y;
}g[230];
double cost[230][230];
int vist[230];
double lowc[230];
double v1=10000.0/60;
double v2=40000.0/60;
void dij(int n){
	for(int i=1;i<=n;i++) vist[i]=0;
	vist[0]=1;
	lowc[0]=0;
	for(int i=1;i<=n;i++) lowc[i]=cost[0][i];
	for(int i=1;i<=n;i++){
		int x;double min=INF;
		for(int j=1;j<=n;j++) {
			if(!vist[j]&&min>lowc[j]) {
			min=lowc[j];x=j;
		}}
		vist[x]=1;
		for(int j=1;j<=n;j++){
			if(lowc[x]+cost[x][j]<lowc[j]) lowc[j]=lowc[x]+cost[x][j];
		}
	}
}
double dis(node a,node b){
	double t=(double)(sqrt)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return t;
}
int main(){
	   freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);
        memset(cost,0x3f,sizeof(cost));
		cin>>g[0].x>>g[0].y>>g[1].x>>g[1].y;
		int a,b;int k=2;
		int cnt=3;
		while(cin>>a>>b){
		if(a==-1&&b==-1) {cnt=k+1;
		continue;}
		g[k].x=a;g[k].y=b;
		k++;
		if(k!=cnt) cost[k-1][k-2]=cost[k-2][k-1]=min(cost[k-1][k-2],dis(g[k-1],g[k-2])/v2);
	}
	for(int i=0;i<k;i++){
	  for(int j=0;j<k;j++)
	    cost[i][j]=min(cost[i][j],dis(g[i],g[j])/v1);
	    cost[i][i]=0;}
	dij(k-1);
	cout<<cost[0][1]<<endl; 
	cout<<lowc[1]<<endl;
	
}
