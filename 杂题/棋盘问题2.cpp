#include<stdio.h>
char board[10][10];
int book[10];//列的标记
int n,k,m,count;
void dfs(int cur){
	int j;
	if(k==m) { count++;return;}
	if(cur>n) return;
	for(j=1;j<=n;j++){
		if(book[j]==0&&board[cur][j]=='#'){
		   book[j]=1;
		   m++;
		   dfs(cur+1);
		   book[j]=0;
		   m--;
		   dfs(cur+1);
	}
	}
}
int main(){
	int i,j;
	while(scanf("%d%d",&n,&k)!=EOF&&(n!=-1||k!=-1)){ 
		getchar();
		count=0;m=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
			   scanf("%c",&board[i][j]);
	  getchar();}
	  dfs(1);
	  printf("%d\n",count);
	  }
}
