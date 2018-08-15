#include<stdio.h>
int main(){
	int i,j,k,a[65]={0},b[65]={0},flag,n;
	while(scanf("%d",&n)!=EOF){
		getchar();
		a[1]=1;
		for(i=2;i<=n&&i<31;i++)
		  a[i]=2*a[i-1]+1;
		b[1]=1;b[2]=3;
		for(i=3;i<=n;i++)
		{
			if(i-30>1) j=i-30;
			else j=1;
			b[i]=2*b[j]+a[i-j];
			for(++j;j<i;j++)
		       {flag=2*b[j]+a[i-j];
		       if(flag<b[i]) b[i]=flag;
	}}
	  printf("%d\n",b[n]);
} }
