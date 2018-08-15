#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double dp[110];
int p[110];
int main(){
	int L;
	while(cin>>L){
		int n;
		int c,t;
		cin>>n>>c>>t;
		int vr,vt1,vt2;
		cin>>vr>>vt1>>vt2;
		for(int i=1;i<=n;i++) cin>>p[i];
		memset(dp,0,sizeof(dp));
		p[n+1]=L;p[0]=0;
		double x;
		for(int i=1;i<=n+1;i++){
			double min=0xffffff;
			for(int j=0;j<i;j++){
			  if((p[i]-p[j])>c) 
			     x=dp[j]+1.0*c/vt1+(p[i]-p[j]-c)*1.0/vt2;
			  else x=dp[j]+(p[i]-p[j])*1.0/vt1;
			  if(j) x+=t;
			  if(x<min) min=x;
		}
		dp[i]=min;}
		double t1=L*1.0/vr;
		if(dp[n+1]>t1) cout<<"Good job,rabbit!"<<endl;
		else cout<<"What a pity rabbit!"<<endl;
	}
	return 0;
}
