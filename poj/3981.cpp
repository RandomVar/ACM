#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	char s[1020];
	while(cin.getline(s,1020)){
		int len=strlen(s);
		for(int i=0;i<len-2;i++) 
		  if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u') {
		  	s[i]='w';s[i+1]='e';
		  	len--;
		  	for(int j=i+2;j<len;j++) s[j]=s[j+1];
		  }
		for(int i=0;i<len;i++) cout<<s[i];
	    printf("\n");
	}
	return 0;
}
