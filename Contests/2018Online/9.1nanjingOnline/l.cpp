#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn = 1e5+100;
ll d[maxn][15];
int vis[maxn][15];
struct node{
	int to;ll cost;
};
struct P{
    ll d;int to;int k;
    bool operator<(const P &b)const{
        return d>b.d;
    }
};
int n,m,k;
vector<node>edge[maxn];
void dij(){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
    d[1][0]=0;
	priority_queue< P >que;
	que.push(P{0,1,0});
	while(!que.empty()){
       P a=que.top();que.pop();
       if(vis[a.to][a.k])  continue;
        vis[a.to][a.k]=1; //or if(d[u]<a.first) continue; optimize in cf 938d
	   	for(int j=0;j<edge[a.to].size();j++){
		   node e=edge[a.to][j];
		  if(!vis[e.to][a.k]&&d[e.to][a.k]>e.cost+d[a.to][a.k]) {
		     d[e.to][a.k]=e.cost+d[a.to][a.k];
             que.push(P{d[e.to][a.k],e.to,a.k});
	      }
        if(a.k<k&&!vis[e.to][a.k+1]&&d[e.to][a.k+1]>d[a.to][a.k])
        {
            d[e.to][a.k+1]=d[a.to][a.k];
            que.push(P{d[e.to][a.k+1],e.to,a.k+1});
        }
           }
    }
}
void init()
{
    for(int i=0;i<=n;i++)
     edge[i].clear();
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       init();
       scanf("%d%d%d",&n,&m,&k);
       for(int i=1;i<=m;i++)
       {
           int u,v;
           ll c;
           scanf("%d%d%lld",&u,&v,&c);
           edge[u].push_back(node{v,c});
         //  edge[v].push_back(node{u,c});
       }
       dij();
       ll ans=INF;
       for(int i=0;i<=k;i++)
         ans=min(ans,d[n][i]);
         printf("%lld\n",ans);
   }
 return 0;
  }

