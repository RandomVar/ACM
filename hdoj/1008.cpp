#include<stdio.h>
int main() {
	int n,a[100]={0},cost,i;
	while(scanf("%d",&n)){
		if(n){

		for(i=0;i<n;i++) scanf("%d",&a[i]);
		cost=0;
		cost+=n*5;
		cost+=a[0]*6;
		for(i=1;i<n;i++) {
			if(a[i-1]<a[i]) cost+=(a[i]-a[i-1])*6;
			else if(a[i-1]>a[i]) cost+=(a[i-1]-a[i])*4;
		}
		printf("%d\n",cost);}
		else break;
	}
}
