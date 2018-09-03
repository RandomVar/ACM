#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=10000000+10;
int d[maxn];
int vis[maxn];
int first[maxn];
int next[maxn];
struct edge{
	int now;int to;int cost;
}e[maxn];
void spfa(int n,int flag){
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	queue<int>que;
	que.push(1);
	while(!que.empty()){
		int t=que.front();
		que.pop();
		vis[t]=0;
		for(int i=first[t];i!=-1;i=next[i]){
			int to = (flag?e[i].to:e[i].now);
			if(d[to]>d[t]+e[i].cost){
				d[to]=d[t]+e[i].cost;
				if(!vis[to]){
					vis[to]=1;
					que.push(to);
				}
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;scanf("%d%d",&n,&m);	
		for(int i = 0; i<=m; i++)  
        first[i] = next[i] = -1;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&e[i].now,&e[i].to,&e[i].cost);
			next[i]=first[e[i].now];
			first[e[i].now]=i;
		}
		spfa(n,1);ll ans=0;
		for(int i=2;i<=n;i++)
		  ans+=d[i];	
		 for(int i = 0; i<=m; i++)  
               first[i] = next[i] = -1;  
    for(int i = 0; i<m; i++)  
     {  
        int now = e[i].now;  
        int to = e[i].to;  
        next[i] = first[to];  
        first[to] = i;  
     } 
		spfa(n,0);
		for(int i=2;i<=n;i++)
		  ans+=d[i];
		printf("%lld\n",ans);
}}
