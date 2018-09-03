#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=11; 
struct node{
	int b,c,p,r;
};
struct state{
	int cur;
	int cost;
	int s;
	bool operator>(const state &other) const
    {
        return cost > other.cost;
    }
};
vector<node>g[maxn];
int vis[maxn][1<<maxn];
int n,m; 
int dij(){
	int ans=-1;
	priority_queue< state,vector<state>,greater<state> >que;
	que.push((state){0,0,1});
	memset(vis,0,sizeof(vis));
	while(!que.empty()){
       state a=que.top();que.pop();
       int u=a.cur;int s=a.s;
	   if(vis[u][s]) continue;
	   vis[u][s]=1; 
	   if(u==n-1)
	   {
	   	ans=a.cost;break;
	   }
	   	for(int j=0;j<g[u].size();j++){
		   node e=g[u][j];
		   int cost=a.cost;
		    if(s&(1<<e.c)){
		      cost+=e.p;
		      que.push((state){e.b,cost,s|1<<(e.b)});
	   }
	   	     else
	   	     {
	   	     	cost+=e.r;
		        que.push((state){e.b,cost,s|1<<(e.b)});
	   }
	}
}
return ans;
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int a,b,c,p,r;
          cin>>a>>b>>c>>p>>r;
          a--;b--;c--;
          g[a].push_back((node){b,c,p,r});
		}
		int x=dij();
		if(x==-1) cout<<"impossible"<<endl;
		else cout<<x<<endl;
	    memset(g,0,sizeof(g));
	}
}
