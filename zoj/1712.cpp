#include<stdio.h>
#include<string.h>
int main(){
	int n,i,k,j;
	double x;
	char s[1000]={'0'};
	while(scanf("%s",s)==1){
		if(s[0]=='0') break;
		k=strlen(s);
		x=0;
		for(i=strlen(s)-1;i>=0;i--){
			int t=1;
			for(j=0;j<=strlen(s)-i-1;j++)
			   t*=2;
			x+=(s[i]-'0')*(t-1);
		}
		printf("%.0lf\n",x);
	}
	return 0;
}
