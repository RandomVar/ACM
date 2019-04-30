#include<bits/stdc++.h>
#define sec second
#define fir first
using namespace std;
const int maxn=1e5+100;
vector<int> edge[maxn], sp;
int dep[maxn], dfn[maxn];
pair<int,int> dp[21][maxn << 1];
struct node
{
  int val;int flag;
  bool operator<(const node &b)const
  {
    return dfn[val]<dfn[b.val];
  }
};
node e[maxn];
void init(int n)
{
    for (int i = 0; i <=n; i++) edge[i].clear();
    sp.clear();
    dep[0]=0;
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();//欧拉序列
    sp.push_back(u);
    for (auto& v : edge[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        sp.push_back(u);
    }
}
/*i,j的lca为i,j进栈之间进出栈的点中进栈时间最早的*/
void initrmq()
{
    int n = sp.size();
    for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).sec;
}

int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    int a,b;
    init(n);
    for(int i=1;i<n;i++)
    {
     scanf("%d%d",&a,&b);
     edge[a].push_back(b);
     edge[b].push_back(a);
    }
 
    dfs(1,0);
    initrmq();
    for(int cas=1;cas<=m;cas++)
    {
      scanf("%d",&a);
      for(int i=1;i<=a;i++)
      {
      scanf("%d",&e[i].val);
      e[i].flag=0;
      }
      scanf("%d",&b);
      for(int i=a+1;i<=a+b;i++)
      {
       scanf("%d",&e[i].val);
       e[i].flag=1;
      }
       sort(e+1,e+1+a+b);
        node pre=e[1];
        int ans=0;
       for(int i=2;i<=a+b;i++)
       {
         if(pre.flag==e[i].flag)
           pre=e[i];
          else {
            ans=max(ans,dep[lca(pre.val,e[i].val)]);
            pre=e[i];
          }
       }
       printf("%d\n",ans);
    }
  }
}