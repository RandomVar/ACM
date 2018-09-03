#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=1<<29; 
int t[40];
int c[40][40];
double d[1<<10][40]; 
double MIN(double a,double b){
	if(a<b) return a;
	return b;
}
int main(){
	int n,m,p,a,b;
	while(cin>>n>>m>>p>>a>>b){
		if(n==0&&m==0&&p==0) break;
		for(int i=0;i<n;i++) cin>>t[i];
    	memset(c,0,sizeof(c));
		for(int i=0;i<p;i++){
			int x,y,z;
			cin>>x>>y>>z;
			c[x][y]=z;
			c[y][x]=z;
		}
   for (int i = 0; i < (1 << n); i++)  
        fill(d[i], d[i] + m + 1, INF); 
	d[(1<<n)-1][a]=0;
	double ans=INF;
	for(int s=(1<<n)-1;s>=0;s--){
		for(int v=1;v<=m;v++){
		 for(int i=0;i<n;i++){
		 	if(s&(1<<i)){
		 		for(int u=1;u<=m;u++){
		 			if(c[v][u]>0){
		 				d[s&~(1<<i)][u]=MIN(d[s&~(1<<i)][u],d[s][v]+(double)c[v][u]/t[i]);
					 }
				 }
			 }
		 } 
	}
	}
	 for (int i = 0; i < (1 << n); i++) 
	ans=MIN(ans,d[i][b]);
	if(ans==INF) printf("Impossible\n");
	else printf("%.3f\n",ans);
}
return 0;
}

