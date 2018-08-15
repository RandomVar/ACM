#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
struct node{
	int j;int f;double r;
}G[maxn];
int cmp(node s1,node s2){
	return s1.r<s2.r;
}
int main(){
	int n,m;
	while(cin>>m>>n&&m!=-1){
		for(int i=1;i<=n;i++) {
		cin>>G[i].j>>G[i].f;G[i].r=(G[i].j*1.0)/G[i].f;
	}
	sort(G+1,G+1+n,cmp);int s=0;double ans=0;
	for(int i=n;i>=1;i--){
		if(m-s>G[i].f) {
		s+=G[i].f;ans+=G[i].j;}
		else {
		  ans+=(m-s)*G[i].r;break;}
	}
	printf("%.3lf\n",ans); 
}}
