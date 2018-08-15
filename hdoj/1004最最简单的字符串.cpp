#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		string s[1020];
		int c[1020]; 
		int k=0;
		getchar();
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++) {
		cin>>s[i];
		for(int j=0;j<i;j++){
			if(s[j]==s[i]) {
				c[j]++;c[i]++;
			}
			else c[i]=1;
		}
	}
	int max=c[0];
	string ans=s[0];
	for(int i=0;i<n;i++) {
		if(c[i]>max) { max=c[i]; ans=s[i];
	}}
	cout<<ans<<endl;
}return 0;}
