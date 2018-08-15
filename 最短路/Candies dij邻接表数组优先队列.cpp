#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=30010; 
struct node{
	int x,cost;int next;
}e[150100];
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
int head[maxn];
int vis[maxn],d[maxn];
int cnt;
void add(int u,int v,int w){
	e[cnt].x=v;
	e[cnt].cost=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
void dij(int n){
	for(int i=1;i<=n;i++){
		vis[i]=0;d[i]=INF;
	}
	priority_queue<qnode>que;
	que.push(qnode(1,0));
	d[1]=0;
	while(!que.empty()){
		qnode pa=que.top();que.pop();
		int u=pa.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].x;
			int cost=e[i].cost;
			if(!vis[v]&&d[v]>d[u]+cost){
				d[v]=d[u]+cost;
				que.push(qnode(v,d[v]));
			}
		}
	}
}
int main(){
	int n,m;
	while(cin>>n>>m){
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
		}
		dij(n);
		cout<<d[n]<<endl;
	}
}
