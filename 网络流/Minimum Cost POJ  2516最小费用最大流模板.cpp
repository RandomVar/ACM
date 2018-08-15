#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=105;
const int maxm=55;
struct edge{
	int from,to,cap,flow,cost;
};
struct MCMF{
	int n,m;
	vector<edge> edges;
	vector<int>g[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)
		  g[i].clear();
		edges.clear();
	}
	void addedge(int from,int to,int cap,int cost){
		edges.push_back((edge){from,to,cap,0,cost});
		edges.push_back((edge){to,from,0,0,-cost});
		m=edges.size();
		g[from].push_back(m-2);
		g[to].push_back(m-1);
	}
	bool bellmanford(int s,int t,int &flow,ll& cost){
		for(int i=0;i<n;i++) d[i]=INF;
		memset(inq,0,sizeof(inq));
		d[s]=0;
		inq[s]=1;
		p[s]=0;
		a[s]=INF;
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			inq[u]=0;
			for(int i=0;i<g[u].size();i++){
				edge& e=edges[g[u][i]];
				if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
					d[e.to]=d[u]+e.cost;
					p[e.to]=g[u][i];
					a[e.to]=min(a[u],e.cap-e.flow);
					if(!inq[e.to]){
						q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(d[t]==INF) return false;
		flow+=a[t];
		cost+=(ll)d[t]*(ll)a[t];
		for(int u=t;u!=s;u=edges[p[u]].from){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
		}
		return true;
	}
	int mincostmaxflow(int s,int t,ll &cost){
		int flow=0;
		cost=0;
		while(bellmanford(s,t,flow,cost));
		return flow;
	}
}ans;
int to[60][60];
int s[60];
int na[60];
int from[60][60];
int y[60][60][60];
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)==3&&(n+m+k)){
		memset(na,0,sizeof(na));
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++)
		  for(int j=0;j<k;j++)
		    {
			scanf("%d",&to[i][j]);
			na[j]+=to[i][j];}
		for(int i=0;i<m;i++)
		  for(int j=0;j<k;j++){
		    scanf("%d",&from[i][j]);
		    s[j]+=from[i][j];}
	  for(int u=0;u<k;u++)
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++)
		    scanf("%d",&y[u][i][j]);
		int flag=0;
	    for(int i=0;i<k;i++){
	    	if(na[i]>s[i]) { flag=1;break;}
		}
		if(flag==1){
			printf("-1\n");continue;
		}
		ll cnt=0;
		int s=n+m;int t=s+1;
		int V=t+1;
		for(int u=0;u<k;u++){
			ans.init(V);
			for(int i=0;i<m;i++) ans.addedge(s,i,from[i][u],0);
			for(int i=0;i<n;i++) ans.addedge(i+m,t,to[i][u],0);
			for(int i=0;i<n;i++)
			  for(int j=0;j<m;j++)
		       ans.addedge(j,i+m,INF,y[u][i][j]);
		       ll cost;
		       ans.mincostmaxflow(s,t,cost);
			    cnt+=cost;
		}
		if(flag==0) printf("%lld\n",cnt);
	}
}
 
