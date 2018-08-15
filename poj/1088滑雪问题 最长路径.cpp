#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=110;
int vis[maxn][maxn];
int h[maxn][maxn];
int f[maxn][maxn];
int m,n;
int Max (int a, int b, int c, int d){  
    int max1 = (a > b) ? a : b;  
    int max2 = (c > d) ? c : d;  
    return (max1 > max2) ? max1 : max2;  
}  
int dfs(int i,int j){
	if(i>m||j>n||i<=0||j<=0) return 0;
	if(vis[i][j]) return f[i][j];
	vis[i][j]=1;
	int a=0,b=0,c=0,d=0;
	if(h[i+1][j]>h[i][j]) a=dfs(i+1,j);
	if(h[i-1][j]>h[i][j]) b=dfs(i-1,j);
	if(h[i][j+1]>h[i][j]) c=dfs(i,j+1);
	if(h[i][j-1]>h[i][j]) d=dfs(i,j-1);
	/*for(int x=-1;x<=1;x++)
	  for(int y=-1;y<=1;y++)不能这么做是因为每一次之间并非选择关系 
	    if(((x==0||y==0)&&!(x==y==0))&&h[i+x][j+y]>h[i][j]) ans=max(ans,dfs(i+x,j+y)+1);*/
	return f[i][j] = Max (a, b, c, d) + 1;;   
} 
int main(){
	while(cin>>m>>n){
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;i++)
		  for(int j=1;j<=n;j++)
		    cin>>h[i][j];
		int ans=0;
		for(int i=1;i<=m;i++)
		  for(int j=1;j<=n;j++)
		    {
			  int t=dfs(i,j);
			  if(t>ans) ans=t;
	}
	cout<<ans<<endl;
}}
