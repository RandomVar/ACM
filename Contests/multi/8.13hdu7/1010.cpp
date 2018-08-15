#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
struct node
{
  ll p[3][3];
};
node mut(node a,node b)
{
  node o;
  clr(o.p,0);
  for(int i = 0;i<3;i++)
  {
    for(int j = 0;j<3;j++)
    {
      for(int k = 0;k<3;k++)
      {
        o.p[i][j] =( a.p[i][k] * b.p[k][j] + o.p[i][j])%mod;
      }
    }
  }
  return o;
}
node quick(node a,ll l)
{
  node origin;
  clr(origin.p,0);
  origin.p[1][1] = origin.p[0][0] = origin.p[2][2] = 1;;
  while(l)
  {
    if(l&1) origin = mut(a,origin);
    a = mut(a,a);
    l/=2;
  }
  return origin;
}

vector<ll>q;
vector<ll>dis;
int cmp(ll a,ll b)
{
  return a>b;
}
ll dp[1000005];
ll csl[100005][2];
ll a,b,c,d;
ll p,n;
ll slove()
{
  int len = q.size();
  int tot = 0;
  for(int i = 1;i<len;i++)
  {
      tot = i;
      if(dis[i+1] >1000000 && dis[i]<=1000000)
      {
        break;
      }
  }
  csl[tot][0] = dp[dis[tot]-1];
  csl[tot][1] = dp[dis[tot]];
  tot++;
  while(tot<len)
  {
    if(n<=dis[tot])
    {
      node a;clr(a.p,0);
      a.p[0][0] = c;a.p[0][1] = d;a.p[0][2] = 1;a.p[1][1]= 1;a.p[2][2] = 1;
      a = quick(a,n-dis[tot-1]);
      return (a.p[0][0]*csl[tot-1][0] + a.p[0][1]*csl[tot-1][1] + a.p[0][2]*q[tot])%mod;
    }
    else
    {
      node a;clr(a.p,0);
      a.p[0][0] = c;a.p[0][1] = d;a.p[0][2] = 1;a.p[1][1]= 1;a.p[2][2] = 1;
      a = quick(a,dis[tot]-dis[tot-1]-1);
      csl[tot][0] = (a.p[0][0]*csl[tot-1][0] + a.p[0][1]*csl[tot-1][1] + a.p[0][2]*q[tot])%mod;
      clr(a.p,0);
      a.p[0][0] = c;a.p[0][1] = d;a.p[0][2] = 1;a.p[1][1]= 1;a.p[2][2] = 1;
      a = quick(a,dis[tot]-dis[tot-1]);
      csl[tot][1] = (a.p[0][0]*csl[tot-1][0] + a.p[0][1]*csl[tot-1][1] + a.p[0][2]*q[tot])%mod;
    }
    tot++;
  }
  tot--;
  node a;clr(a.p,0);
  a.p[0][0] = c;a.p[0][1] = d;a.p[0][2] = 1;a.p[1][1]= 1;a.p[2][2] = 1;
  a = quick(a,n-dis[tot]);
  return (a.p[0][0]*csl[tot][0] + a.p[0][1]*csl[tot][1])%mod;
}
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>c>>d>>p>>n;
    q.clear();
    dis.clear();
    for(int i = 1;i*i<=p;i++)
    {
      q.pb(p/i);
      if(i*i != p)
      q.pb(i);
    }
    sort(q.begin(),q.end(),cmp);
    int len = q.size();
    for(int i = 0;i<len;i++)
    {
      dis.pb(p/q[i]);
    }
    dp[1] = a,dp[2] = b;
    for(int i = 3;i<=min(n,1LL*1000000);i++)
    {
      dp[i] = c*dp[i-2]+d*dp[i-1]+p/i;
      dp[i]%=mod;
    }
    if(n<=1000000)
    {
      cout<<dp[n]<<endl;
    }
    else
    {
      cout<<slove()<<endl;
    }
  }
  return 0;
}