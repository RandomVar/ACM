#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 

const int maxn=5*105;

vector<node>g[maxn];
int level[maxn];
int iter[maxn];
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

int max_flow(int s,int t){
	int flow=0;
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
	int n,f,d;
	while(cin>>n>>f>>d){
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			for(int j=1;j<=u;j++){
				int x;cin>>x;
				addnode(x,f+2*i-1,1);
			}
			addnode(f+2*i-1,f+2*i,1);
			for(int k=1;k<=v;k++){
				int y;cin>>y;
				addnode(f+2*i,f+2*n+y,1);
			}
		}
		for(int i=1;i<=f;i++)
		 addnode(0,i,1);
		for(int i=f+2*n+1;i<=f+2*n+d;i++)
		 addnode(i,f+2*n+d+1,1);
		printf("%d\n",max_flow(0,f+2*n+d+1));
	}
}
