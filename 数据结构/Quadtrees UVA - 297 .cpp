#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2<<10;
char tree[maxn];
int ans;
void dfs1(int i){
   char x;
   cin>>x;
   if((tree[i]=='e')||(tree[i]=='p'&&x=='f')) tree[i]=x;
   if(x=='p') {
   	for(int u=1;u<=4;u++)
   	  dfs1(i*4+u);
   }
   return;
} 
void dfs2(int i,int k){
	if(tree[i]=='f') ans+=pow(4,5-k);
	if(tree[i]=='p'){
		for(int u=1;u<=4;u++)
   	     dfs2(i*4+u,k+1);
	}
	return;
}
int main(){
	int n;cin>>n;
	while(n--){
		for(int i=0;i<maxn;i++)
		  tree[i]='e';
		ans=0;
		dfs1(0);
		dfs1(0);
		dfs2(0,0);
		printf("There are %d black pixels.\n",ans);
	}
}
