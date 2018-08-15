#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1110;
int d[maxn];
int n;
typedef pair<int,int>P;
struct node{
	int to;int cost;
};
vector<node>g[maxn];
void dij(){
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	priority_queue< P,vector<P>,greater<P> >que;
	que.push(P(0,1));
	while(!que.empty()){
       P a=que.top();que.pop();
       int u=a.second; 
	   	for(int j=0;j<g[u].size();j++){
		   node e=g[u][j];
		 if(d[e.to]>e.cost+d[u]) {
		 d[e.to]=e.cost+d[u];que.push(P(d[e.to],e.to));
	   }	
	}
}}
int main(){
	int t;
	while(cin>>t>>n){
		for(int i=1;i<=t;i++){
			int x,y,z;
			cin>>x>>y>>z; 
			node a;a.to=y;a.cost=z;
			node b;b.to=x;b.cost=z;
			g[x].push_back(a);
			g[y].push_back(b);
		}
		dij();
		printf("%d\n",d[n]);
	}
	
}

