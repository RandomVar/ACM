#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<vector> 
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
const int maxn=1000010;
struct edge{
	int to;int cost;
};
int a[maxn],b[maxn],c[maxn];
int lowc[maxn];
vector<edge>g[maxn];
int use[maxn];
void spfa(int n){
	memset(lowc,0x3f,sizeof(lowc));
	memset(use,0,sizeof(use));
	lowc[0]=0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int v=que.front();que.pop();use[v]=0;
		for(int i=0;i<g[v].size();i++){
			edge e=g[v][i];
			if(lowc[e.to]>lowc[v]+e.cost){
			  lowc[e.to]=lowc[v]+e.cost;
			  if(!use[e.to]){
			  	que.push(e.to);use[e.to]=1;
			  }}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;scanf("%lld%lld",&n,&m);	
			for(int i=0;i<n;i++)
		  { g[i].clear();}

		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			edge e;e.cost=c[i];e.to=b[i]-1;
			g[a[i]-1].push_back(e);
		}	
		spfa(n);
		ll ans=0;
		for(int i=0;i<n;i++)
		  {ans+=lowc[i];}
		  for(int i=0;i<n;i++)
		  { g[i].clear();}
		for(int i=0;i<m;i++){
			edge e;e.cost=c[i];e.to=a[i]-1;
			g[b[i]-1].push_back(e);
		}
		spfa(n);
		for(int i=0;i<n;i++)
		  {ans+=lowc[i];}
		printf("%lld\n",ans);
	
	}
}
