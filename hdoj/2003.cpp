#include<stdio.h>
#include<math.h>
int main(){
	double n;
	while(scanf("%lf",&n)!=EOF){
		getchar();
		printf("%.2lf\n",fabs(n));
	}
}
