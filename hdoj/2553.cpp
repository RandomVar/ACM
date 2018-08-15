#include<stdio.h>
int eq[11];
int c[11];
int count;int n; 
int ifput(int row,int column){
	int i;
	for(i=1;i<row;i++) {
	if(eq[i]==column) return 0;
	if((eq[i]+i)==(column+row)) return 0;
	if((eq[i]-i)==(column-row)) return 0;
}
   return 1;
   }
void eightqueen(int row,int column){
	int j;
	  for(j=1;j<=column;j++){
		if(ifput(row,j)){
			if(row==column) {c[column]++;return;}
			eq[row]=j;
			eightqueen(row+1,column);
			eq[row]=0;
		}
	}}
int main(){
	int i;
	for(i=1;i<=10;i++){
		c[i]=0;
		eightqueen(1,i);
	}
	while(scanf("%d",&n)!=EOF&&n!=0){
		getchar();
	    printf("%d\n",c[n]);	
	}
	return 0;
} 
