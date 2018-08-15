#include<stdio.h>
#include<math.h>
int main(){
	double y,sum;
	int x,n,i;
	while(scanf("%d%d",&x,&n)!=EOF){
		getchar();
		y=x*1.0;
		sum=0.0;
		for(i=0;i<n;i++){
			sum+=y;
			y=sqrt(y);
		}
		  printf("%.2lf\n",sum);
	}
	return 0;
}
