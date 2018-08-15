#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
double p[110];int w[110];
double dp[11030];
int main(){
	int n;
	cin>>n;
	while(n--){
		double pr;int cr;//cr是总的抢劫个数 
		memset(w,0,sizeof(w));
		memset(p,0,sizeof(p));
		cin>>pr>>cr;
		for(int i=1;i<=cr;i++) cin>>w[i]>>p[i];
		memset(dp,0,sizeof(dp));
		dp[0]=1;//逃脱的概率
		int MAX=0;
		for(int i=1;i<=cr;i++) MAX+=w[i];
		for(int j=1;j<=cr;j++){
			for(int i=MAX;i>=w[j];i--)
			  dp[i]=max(dp[i-w[j]]*(1.0-p[j]),dp[i]);
		}
		int i;
		for(i=MAX;dp[i]<1.0-pr;i--);
		cout<<i<<endl;
	}
	return 0;
}
