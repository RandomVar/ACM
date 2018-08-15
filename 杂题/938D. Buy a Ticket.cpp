#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f;
const int maxn=2*1e5+10;
ll n;
ll ans[maxn];
typedef pair<ll,ll>P;
struct node{
	ll to;ll cost;
};
vector<node>g[maxn];
void dij(){
	priority_queue< P,vector<P>,greater<P> >que;
	que.push(P(0,0));
	ans[0]=0;
	while(!que.empty()){
       P a=que.top();que.pop();
       ll u=a.second;
       if(ans[u]<a.first) continue;
	   	for(ll j=0;j<g[u].size();j++){
		   node e=g[u][j];
		 if(ans[e.to]>e.cost+ans[u]) {
		 ans[e.to]=e.cost+ans[u];que.push(P(ans[e.to],e.to));
	   }
	}
}}

int main(){
  ll m;
  scanf("%I64d%I64d",&n,&m)==2;
    for(ll i=0;i<m;i++){
        ll u,v,w;
        scanf("%I64d%I64d%I64d",&u,&v,&w);
        g[u].push_back(node{v,2*w});
        g[v].push_back(node{u,2*w});
    }
    memset(ans,0x3f,sizeof(ans));
    ll MIN=INF;ll u=-1;
    for(ll i=1;i<=n;i++){
        ll t;
        scanf("%I64d",&t);
        g[0].push_back(node{i,t});
        if(MIN>ans[i]) {MIN=ans[i];u=i;}}
    dij();
    for(ll i=1;i<n;i++)
        printf("%I64d ",ans[i]);
   printf("%I64d\n",ans[n]);
  return 0;
}
