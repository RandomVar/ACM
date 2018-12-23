#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn =2e5+100;
typedef pair<ll,int> P;
ll d[maxn];
int vis[maxn];
int n;
struct node{
	int to;ll cost;
};
ll ans;
ll co[maxn];
vector<node>g[maxn];
void dij(int s){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
    memset(co,0,sizeof(co));
    d[s]=0;
	priority_queue< P,vector<P>,greater<P> >que;
	que.push(P(0,s));
	while(!que.empty())
    {
       P a=que.top();
       que.pop();
       int u=a.second;
       if(vis[u])  continue;
        vis[u]=1; 
        ans+=co[u];
	   	for(int j=0;j<g[u].size();j++){
		   node e=g[u][j];
		  if(!vis[e.to]&&(d[e.to]>e.cost+d[u]||(d[e.to]==e.cost+d[u]&&co[e.to]>e.cost))) 
          {
		     d[e.to]=e.cost+d[u];
             que.push(P(d[e.to],e.to));
	          co[e.to]=e.cost;
             // cout<<e.to<<" "<<co[e.to]<<endl;
          }
	}}
}
int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)==2)
   {
       for(int i=1;i<=m;i++)
       {
           int u,v;ll w;
           scanf("%d%d%lld",&u,&v,&w);
           g[u].push_back(node{v,w});
           g[v].push_back(node{u,w});
       }
       int t;
       ans=0;
       scanf("%d",&t);
       dij(t);
       printf("%lld\n",ans);
   }
}