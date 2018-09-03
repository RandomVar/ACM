#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f; 
const ll maxn=1000100;
struct edge{
	ll to;ll cost;
};
ll lowc[maxn];
ll lowc2[maxn];
typedef pair<ll,ll> P;
vector<edge>g[maxn];
vector<edge>gb[maxn];
int use[maxn];
void dij1(ll n){
	memset(lowc,0x3f,sizeof(lowc));
	memset(use,0,sizeof(use));
	lowc[0]=0;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,0));
	while(!que.empty()){
		P p=que.top();que.pop();
		ll v=p.second;
		if(use[v]) continue;
		use[v]=1;
		for(ll i=0;i<g[v].size();i++){
			edge e=g[v][i];
			if(lowc[e.to]>lowc[v]+e.cost){
			  lowc[e.to]=lowc[v]+e.cost;
			  que.push(P(lowc[e.to],e.to));}
		}
	}
}
void dij2(ll n){
	memset(lowc2,0x3f,sizeof(lowc2));
	memset(use,0,sizeof(use));
	lowc2[0]=0;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,0));
	while(!que.empty()){
		P p=que.top();que.pop();
		ll v=p.second;
		if(use[v]) continue;
		use[v]=1;
		for(ll i=0;i<gb[v].size();i++){
			edge e=gb[v][i];
			if(lowc2[e.to]>lowc2[v]+e.cost){
			  lowc2[e.to]=lowc2[v]+e.cost;
			  que.push(P(lowc2[e.to],e.to));}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m;scanf("%lld%lld",&n,&m);	
			for(int i=0;i<n;i++)
		  { g[i].clear();gb[i].clear();}
		for(ll i=0;i<m;i++){
			ll x,y;ll z;
			scanf("%lld%lld%lld",&x,&y,&z);
			edge e;e.cost=z;e.to=y-1;
			g[x-1].push_back(e);
			edge f;f.cost=z;f.to=x-1;
			gb[y-1].push_back(f);
		}	
		dij1(n);
		dij2(n);
		ll ans=0;
		for(ll i=0;i<n;i++)
		  {ans+=lowc[i]+lowc2[i];}
		printf("%lld\n",ans);
	
	}
}
