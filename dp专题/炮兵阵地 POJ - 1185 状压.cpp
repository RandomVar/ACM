#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
char map[15][110]; 
int dp[110][110][110];
int v[110]; 
int sum[110];
int m;
int getsum(int s) 
{
    int ret = 0;
    for (; s; s >>= 1)
        if (s & 1) ret++;
    return ret;
}
void init(){
	int cnt=0;
	for(int i=0;i<(1<<10);i++){
		if((i&(i<<1))==0&&(i&(i<<2))==0){
		  v[cnt]=i;
		  sum[cnt++]=getsum(i);
	}}
}
int check(int state,int row){
	for(int i=0;i<m;i++)
	 if((state&(1<<i))&&map[row][i]=='H') return 1;
	 return 0;
}
int main(){
	int n;
    scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		  for(int j=0;j<m;j++)
		    scanf("%c",&map[i][j]);
		init();
        for(int i=1;i<=n;i++){
        	for(int j=0;v[j]<(1<<m);j++){
        		if(check(v[j],i)) continue;
        	    if(i==1) {
        	    //for(int k=0;k<(1<<m);k++)
        	    	dp[i][0][j]=sum[j];
				continue;
				}
			for(int k=0;v[k]<(1<<m);k++){
				if(check(v[k],i-1)==0&&(v[j]&v[k])==0){
			  for(int u=0;v[u]<(1<<m);u++){
			     if((v[j]&v[u])==0) {
				  dp[i][k][j]=max(dp[i][k][j],dp[i-1][u][k]+sum[j]);
			}}
		}	}}}	
		int ans=0;
	for(int i=0;v[i]<(1<<m);i++)
	  for(int j=0;v[j]<(1<<m);j++)
	   ans=max(ans,dp[n][j][i]);
	printf("%d\n",ans);
	
}
