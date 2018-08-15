#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
struct node{
	int h,a,c;
}g[410];
int cmp(node a,node b){
	return a.a<b.a;
}
int dp[40100];
int num[40100];
int main(){
	int k;
	while(cin>>k){
	int maxa=-1;
	for(int i=1;i<=k;i++){
	 cin>>g[i].h>>g[i].a>>g[i].c;
	 if(maxa<g[i].a) maxa=g[i].a;}
	 sort(g+1,g+1+k,cmp);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
	for(int i=1;i<=k;i++){
		memset(num,0,sizeof(num));
		  for(int j=g[i].h;j<=g[i].a;j++){
		  	  if(dp[j-g[i].h]&&!dp[j]&&num[j-g[i].h]<g[i].c){
			dp[j]=1;
			num[j]=num[j-g[i].h]+1;
		}}
	}
	int ans=0;
	for(int i=0;i<=maxa;i++)
	  if(dp[i]) ans=i;
	cout<<ans<<endl;
} }
