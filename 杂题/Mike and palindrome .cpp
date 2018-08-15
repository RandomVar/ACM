#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	char s[20];
	while(cin>>s){
		int flag=0;
		int len=strlen(s);
		for(int i=0;i<len/2;i++){
		   if(s[i]==s[len-i-1]) continue;
		   else flag++;
		}
		if(flag==1) printf("YES\n");
		else if(len&1&&flag==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
