/**建n个01字典树*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;


const int maxn=1e5+100;
int cnt;
int root[maxn];
int vis[maxn];
vector<int>d[maxn];
int nex[maxn*300][2];
int v[maxn*300];
int newnode()
{
  for(int i=0;i<2;i++)
   nex[cnt][i]=-1;
 v[cnt++]=0x3f3f3f3f;
  return cnt-1;
}
void insert(int x)
{
for(int j=0;j<d[x].size();j++)
{
  // cout<<"*"<<d[x][j]<<endl;
  int now=root[d[x][j]];
  v[now]=min(v[now],x);
  for(int i=20;i>=0;i--)
  {
    int id=((x>>i)&1);
    if(nex[now][id]==-1) nex[now][id]=newnode();
    now=nex[now][id];
    v[now]=min(v[now],x);
  }
}
}
ll query(int bian,ll ma,ll x)
{
  // cout<<bian<<" "<<ma<<" "<<x<<endl;
  int now=root[bian];
  ll val=0;
  for(int i=20;i>=0;i--)
  {
    int id=((x>>i)&1);
    id^=1;
    // cout<<nex[now][id]<<" "<<nex[now][id^1]<<endl;
    if(nex[now][id]!=-1&&v[nex[now][id]]<=ma)
       {
         now=nex[now][id];
         val+=(id<<i);
       }
    else if(nex[now][id^1]!=-1&&v[nex[now][id^1]]<=ma)
    {
       now=nex[now][id^1];
       val+=((id^1)<<i);
    }
    else return -1;
    // cout<<i<<" "<<val<<endl;
  }
  return val;
}
void Init()
{
  for(int i=1;i<maxn;i++)
  {
      for(int j=i;j<maxn;j+=i)
        {
          d[j].push_back(i);
        }
    }

  cnt=0;
  for(int i=1;i<maxn;i++)
   root[i]=newnode();
}

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
  int q;
  while(scanf("%d",&q)==1)
  {
  Init();
 memset(vis,0,sizeof(vis));
  for(int i=1;i<=q;i++)
  {
    int op;
    scanf("%d",&op);
  //  cout<<op<<endl;
    if(op==1)
    {
      int u;
      scanf("%d",&u);
      if(vis[u]) continue;
      vis[u]=1;
     insert(u);
    }
    else
    {
      int x,k,s;
      scanf("%d%d%d",&x,&k,&s);
      if(x%k)
        {
          printf("-1\n");
          continue;
        }
      printf("%lld\n",query(k,s-x,x));
    }
  }
}
}
