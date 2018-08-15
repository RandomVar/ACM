#include<stdio.h>
int main(){
	int year,month,day,count=0;
	while(scanf("%d%*c%d%*c%d",&year,&month,&day)!=EOF){
		getchar();
		while(1){
		if(month==1) {count=day;break;}
		else count=31;
		if(month==2) {count+=day;break;}
		else{ if((year%4==0&&year%100!=0)||year%400==0) count+=29;
		    else count+=28;}
		if(month==3) {count+=day;break;}
		else count+=31;
		 if(month==4) {count+=day;break;}
		else count+=30;
		if(month==5) {count+=day;break;}
		else count+=31;
		if(month==6) {count+=day;break;}
		else count+=30;
		if(month==7) {count+=day;break;}
		else count+=31;
		if(month==8) {count+=day;break;}
		else count+=31;
		if(month==9) {count+=day;break;}
		else count+=30;
		if(month==10) {count+=day;break;}
		else count+=31;
		if(month==11) {count+=day;break;}
		else count+=30;
		if(month==12) {count+=day;break;}
		}
		printf("%d\n",count);
	}
}
