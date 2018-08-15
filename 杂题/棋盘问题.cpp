#include<stdio.h>
int chessboard(int a[][10],int n,int k){
	int i,j,x,y,z,t,b[n][10],count=0;
	if(n>=2&&k>0){
		for(i=1,j=1;j<=n;j++){
	  	  if(a[i][j]==1){
	  	  	x=1;y=1;
	  	  	  for(z=2;z<=n;z++){
	  	  	  	for(t=1;t<=n;t++)
	  	  	  	  if(t!=j) b[x][y++]=a[z][t];
	  	  	  	  else b[x][y++]=0;
	  	  	  	  x++;
				  }
	  	  	  count+=chessboard(b,n-1,k-1);
			}}}
	if(n==1) { printf("%d",a[1][1]); if(a[1][1]==1) count++;}
	return count;
}
int main(){
	int n,i,j,k;
	while(scanf("%d%d",&n,&k)!=EOF&&(n!=-1||k!=-1)){ 
		getchar();
		int a[n+1][10];
		int i,j;
		char ch;
		for(i=1;i<=n;i++){
		  for(j=1;j<=n;j++)
		{
			ch=getchar();
	      if(ch=='#') a[i][j]=1;
		else if(ch=='.') a[i][j]=0;
	  }
	  getchar();}
	  printf("%d\n",chessboard(a,n,k));
	  }
}
