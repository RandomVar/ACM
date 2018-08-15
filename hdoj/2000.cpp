#include<stdio.h>
#include<string.h>
int main(){
	char s[4],t;
	int i=0,k=0;
	while(gets(s)!=NULL){
    if(s[0]>s[1]){t=s[0];s[0]=s[1];s[1]=t;}
	if(s[0]>s[2]) {t=s[0];s[0]=s[2];s[2]=t;}
	if(s[1]>s[2]){t=s[1];s[1]=s[2];s[2]=t;}
	printf("%c %c %c\n",s[0],s[1],s[2]);
} }
