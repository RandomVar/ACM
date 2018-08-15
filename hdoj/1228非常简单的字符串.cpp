#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>//重要的头文件 
using namespace std;
string temp[11]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
int main(){
	string s;
	while(1){
	int a=0;
	 while(cin>>s,s!="+"){
		for(int i=0;i<10;i++){
			if(s==temp[i]) {a=10*a+i;break;}
		}
	}
	int b=0;
	while(cin>>s,s!="="){
		for(int i=0;i<10;i++){
			if(s==temp[i]) {b=10*b+i;break;}
		}
	}
	if(a+b==0) break;
	cout<<a+b<<endl;}
	return 0;
}
