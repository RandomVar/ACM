#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[150000];
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int a[7];int k=0;
	while(cin>>a[1]){
		int ch=0;
		k++;
		int m=a[1];
		for(int i=2;i<=6;i++) {cin>>a[i];m+=a[i]*i;}
		if(m==0) break;
		memset(dp,0,sizeof(dp));
		if(m%2==1) {
			printf("Collection #%d:\n",k);
			printf("Can't be divided.\n");}
		else{
		for(int i=1;i<=6;i++){
			for(int j=1;j<=a[i];j++){
				for(int k=m/2;k>=0;k--)
				   if(k>=j*i) dp[k]=max(dp[k],dp[k-j*i]+j*i);
			}}
		printf("Collection #%d:\n",k);
		if(dp[m/2]==m/2) printf("Can be divided.\n");
		else printf("Can't be divided.\n");}
		printf("\n");
	}
return 0;
}
