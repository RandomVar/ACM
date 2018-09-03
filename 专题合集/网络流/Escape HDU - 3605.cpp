#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
const int maxn=3000;
struct node{
	int t,cap,rev;
};
vector<node>g[maxn];
int level[maxn];
int iter[maxn];
int map[maxn];
void addnode(int x,int y,int z){
	g[x].push_back((node){y,z,g[y].size()});
	g[y].push_back((node){x,0,g[x].size()-1});
}
void bfs(int s){
	queue<int>que;
	memset(level,-1,sizeof(level));
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<g[v].size();i++){
			node &e=g[v][i];
			if(e.cap>0&&level[e.t]<0){
				level[e.t]=level[v]+1;
				que.push(e.t);
			}
		}
	}
}
int dfs(int s,int t,int f){
	if(s==t) return f;
	for(int &i=iter[s];i<g[s].size();i++){
	  node &e=g[s][i];
	  if(e.cap>0&&level[e.t]>level[s]){
	  	int d=dfs(e.t,t,min(f,e.cap));
	  	if(d>0){
	  		e.cap-=d;
	  		g[e.t][e.rev].cap+=d;
	  		return d;
		  }
	  } 
}
return 0;}

ll max_flow(int s,int t){
	ll flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		memset(g,0,sizeof(g));
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++){
			int res=0;
			for(int j=0;j<m;j++){
				int t;
				scanf("%d",&t);
				if(t==1) res+=1<<j;
			}
			map[res]++;
			}
		int s=(1<<m)+m;
		int e=(1<<m)+m+1;
		for(int i=0;i<(1<<m);i++){
		   for(int j=0;j<m;j++)
			if(i&(1<<j)) addnode(i,(1<<m)+j,map[i]);
		}
		for(int i=0;i<m;i++){
			int t;scanf("%d",&t);
			addnode((1<<m)+i,e,t);
		}
		for(int i=0;i<(1<<m);i++)
		  addnode(s,i,map[i]);
		if(max_flow(s,e)<n) printf("NO\n");
		else printf("YES\n");
	}
}
