#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
char s[3][20];
char a[][20]={"rat","ox","tiger","rabbit","dragon","snake","horse","sheep","monkey","rooster","dog","pig"};
int find(char x[20]){
	for(int i=0;i<12;i++)
	  if(strcmp(x,a[i])==0) return i;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[0]>>s[1];
	int x=find(s[0]);int y=find(s[1]);
	if(x<y) cout<<y-x<<endl;
	else cout<<12+y-x<<endl;
	}
	return 0;
}
