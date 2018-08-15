#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=105;
int map[maxn][maxn];
void dfs(int x,int y,int n,int m){
	if(x>=n||y>=m||x<0||y<0) return;
	if(map[x][y]==0) return;
	map[x][y]=0;
	for(int i=-1;i<=1;i++)
	  for(int j=-1;j<=1;j++){
	     dfs(x+i,y+j,n,m);}
	  }
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			getchar();
			for(int j=0;j<m;j++)
			  {
			  	char a;a=getchar();
			  	if(a=='W') map[i][j]=1;
			  	else if(a=='.') map[i][j]=0;
			  }
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++)
		    if(map[i][j]==1) {
			dfs(i,j,n,m);cnt++;}
		cout<<cnt<<endl;
	}
} 
