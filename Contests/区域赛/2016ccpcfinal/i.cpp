#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=210;
const int inf=0x3f3f3f3f;
typedef pair<int,int>P;
vector<P>edge[maxn];
vector<P>he[maxn];
priority_queue<P,vector<P>,greater<P> >que;
int d[maxn];
int p[maxn];
ll dp[10100];
int m;
void dij()
{
  while(!que.empty())
  {
    P t=que.top();
    que.pop();
    int u=t.second;
    // cout<<u<<endl;
      if(t.first>d[u]) continue;

    for(int i=0;i<edge[u].size();i++)
    {
      int v=edge[u][i].first;
      int ji=edge[u][i].second;
     int val=0;
     for(int j=0;j<he[ji].size();j++)
     {
          P x=he[ji][j];
         val+=d[x.first]*x.second;
         if(val>m) break;
     }
     if(val>m) continue;
     if(val<d[v])
       {
         d[v]=val;
         que.push(make_pair(val,v));
       }
    }
  }
}
void init(int n,int k)
{
  for(int i=0;i<=n;i++)
    edge[i].clear();

  for(int i=0;i<=k;i++)
     he[i].clear();
  while(!que.empty())
    que.pop();
}

int main()
{
  int t;int cas=0;
  scanf("%d",&t);
  while(t--)
  {
    int n,k;
    scanf("%d%d%d",&m,&n,&k);
    int op;
    init(n,k);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&op);
      if(op==1)
      {
        scanf("%d%d",&d[i],&p[i]);
        if(d[i]>m) d[i]=inf;
        else que.push(make_pair(d[i],i));
      }
      else
      {
        scanf("%d",&p[i]);
        d[i]=inf;
          // que.push(make_pair(inf,i));
      }
    }

    for(int i=1;i<=k;i++)
    {
      int x,y,u,v;
      scanf("%d%d",&x,&y);
     for(int j=0;j<y;j++)
      {
        scanf("%d%d",&u,&v);
        edge[u].push_back(make_pair(x,i));
        he[i].push_back(make_pair(u,v));
      }
    }
    // cout<<1<<endl;
    dij();
    // for(int i=1;i<=n;i++)
    //  cout<<d[i]<<" ";
    // cout<<endl;
  ll ans=0;
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++){
    for(int s=d[i];s<=m;s++){
      dp[s]=max(dp[s],dp[s-d[i]]+p[i]);
}}

    for(int s=0;s<=m;s++)
       ans=max(ans,dp[s]);

     printf("Case #%d: %lld\n",++cas,ans);
  }
}
