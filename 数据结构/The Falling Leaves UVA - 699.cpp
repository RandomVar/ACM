#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int a[200];
int build(int p){
	int x;cin>>x;
	if(x==-1&&p==100) return 0; 
	if(x==-1) return 1;
	a[p]+=x;
	build(p-1);
	build(p+1);
	return 1;
}
int main(){
	int k=0;
	while(1){
		k++;
		memset(a,0,sizeof(a));
		int t=build(100);
		if(t==0) break;
		printf("Case %d:\n",k);
		int c=0;
		for(int i=0;i<200;i++){
		  if(a[i]!=0) {
		  	c++;
		  	if(c==1) printf("%d",a[i]);
		    else printf(" %d",a[i]);}}
		printf("\n\n");
	}
} 
