#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
char str[10][5];
char a[150]; 
int main(){
	int n;int cnt=0;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		for(int i=0;i<n;i++)
		  scanf("%s",str[i]);
		scanf("%s",a);
		int k;
		scanf("%d",&k);
		cnt++;
	printf("S-Tree #%d:\n",cnt);
	int ji=0;
	for(int i=0;i<n;i++)
	 ji+=pow(2,i);
	 //cout<<ji<<endl;
	for(int i=0;i<k;i++){
		char c[10];
	    scanf("%s",c);
	    int t=1;
	    for(int j=0;j<n;j++){
	    	if(c[j]=='0') t=t*2;
	    	else if(c[j]=='1') t=t*2+1;
		}
		printf("%c",a[t-ji-1]);
	}
	printf("\n\n");
}} 
