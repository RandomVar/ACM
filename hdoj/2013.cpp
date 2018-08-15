#include<stdio.h>
int main(){
	int n,i,num;
	while(scanf("%d",&n)!=EOF){
		num=1;
		for(i=0;i<=n-2;i++)
		  num=(num+1)*2;
		printf("%d\n",num);
	}
} 
