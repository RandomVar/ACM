/*
树上贪心

*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mpr make_pair
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;

/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
vector<int>edge[maxn];
int p[maxn];
int f[maxn];

struct node{
    ll a,b;//int id;
}s[maxn];
node operator +(const node &a,const node  &b) {//合并的时候注意
	ll u=max(a.a,a.a-a.b+b.a);
	return (node){u,u-a.a+a.b-b.a+b.b};
}
bool operator <(const node &a,const node &b) {
	if (a.a<=a.b&&b.a>b.b) return 1;
	if (a.a>a.b&&b.a<b.b) return 0;
 
	if (a.a<=a.b&&b.a<=b.b) return a.a<b.a;
	if (a.a>a.b&&b.a>b.b) return a.b>b.b;
	return 0;
}
void init(int n){
  for(int i=1;i<=n;i++)
    p[i]=i;
for(int i=0;i<=n;i++)
 edge[i].clear();
}

int find(int x){
 return x==p[x]?x:find(p[x]);
}

void dfs(int u,int pre)
{
      f[u]=pre;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==pre)
          continue;
        dfs(v,u);
    }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        init(n);
        s[1].a=s[1].b=0;
        for(int i=2;i<=n;i++)
        {
            scanf("%lld%lld",&s[i].a,&s[i].b);
        }

        for(int i=2;i<=n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
        }

        dfs(1,0);
        set<pair<node,int> >hs;
        for(int i=2;i<=n;i++)
          hs.insert(make_pair(s[i],i));
          while(!hs.empty())
          {
              int u=hs.begin()->sec;
              hs.erase(make_pair(s[u],u));
              int v=find(f[u]);
              p[u]=v;
              if(v!=1) hs.erase(make_pair(s[v],v));
              s[v]=s[v]+s[u];
              if(v!=1) hs.insert(make_pair(s[v],v));
          }
          printf("%lld\n",s[1].a);
    }

 return 0;
  }

