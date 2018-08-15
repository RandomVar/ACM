#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath> 
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
double x[210],y[210];
double cost[210][210];
int main(){
	int n;int t=0;
	while(scanf("%d",&n)==1&&n!=0){
		t++;
		memset(cost,0,sizeof(cost));
		for(int i=1;i<=n;i++)
		  scanf("%lf%lf",&x[i],&y[i]);
		for(int i=1;i<=n;i++)
		  for(int j=i+1;j<=n;j++){
		    cost[i][j]=sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
		    cost[j][i]=cost[i][j];
			}
		for(int k=1;k<=n;k++)
		  for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++)
		      cost[i][j]=min(cost[i][j],max(cost[i][k],cost[k][j]));
		printf("Scenario #%d\n",t);
		printf("Frog Distance = %.3lf\n",cost[1][2]);
		printf("\n");
	}
}
