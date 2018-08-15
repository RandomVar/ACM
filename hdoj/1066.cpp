#include<stdio.h>
digit (int n){
	int x;
	if(n==1) return 1;
	if(n%5==0) {for(x=n*digit(n-1);x%10==0;x=x/10);return x;}
	x=n*digit(n-1); return x%100;
	}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		getchar();
		int x;
		for(x=digit(n);x%10==0;x=x/10);
		printf("%d\n",x);
	}
	return 0;
} 
