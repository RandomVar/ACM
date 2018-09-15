#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define mem(a,x) memset(a,x,sizeof(a))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int maxn = 210*3;
typedef long long ll;

vector<int>v;
int getid(int x)
{
  return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct node
{
  int u,v,c;
}a[maxn];
struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w)
        : from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn]; //是否在队列中
    int d[maxn];   //bellmanford
    int p[maxn];   //上一条弧
    int a[maxn];   //可改进量
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.pb(Edge(from, to, cap, 0, cost));
        edges.pb(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    bool BellmanFord(int s, int t, int& flow, ll& cost)
    {
        for (int i = 0; i < n; i++) d[i] = inf;
        mem(inq, 0);
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = inf;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < (int)G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == inf) return false; // 当没有可增广的路时退出
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    int MincostMaxflow(int s, int t, ll& cost)
    {
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost));
        return flow;
    }
};
MCMF ans;
signed main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
	int T;
	scanf("%lld",&T);
	while(T--)
	{
    int N,k,M;
		scanf("%lld%lld%lld",&N,&k,&M);
    v.clear();
		for(int i=1;i<=M;i++)
		{
			scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].c);
      v.pb(a[i].u);v.pb(a[i].v);v.pb(a[i].v+1);
		}
  sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
  int m=v.size();
  ans.init(m+10);
  int s=m+5;int t=m+6;
  ans.AddEdge(s,1,k,0);
  ans.AddEdge(m,t,k,0);
  for(int i=1;i<=m-1;i++)
   ans.AddEdge(i,i+1,k,0);
  // for(int i=0;i<m;i++)
    // ans.AddEdge(s,i+1,k,0),ans.AddEdge(i+1,t,k,0);
  for(int i=1;i<=M;i++)
  {
    int u=getid(a[i].u);
    int v=getid(a[i].v+1);
    //cout<<u<<" "<<v<<endl;
    ans.AddEdge(u,v,1,-a[i].c);
  }
  ll cost=0;
  ans.MincostMaxflow(s,t,cost);
  // cout<<x<<endl;
		printf("%lld\n",-cost);
	}
	return 0;
}
