#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
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
const int maxn=1e5+100;
const int block=1000;
ll bit[maxn];
ll s[maxn];
int deep[maxn];
int st[maxn],ed[maxn];
vector<int>mp[maxn];
vector<int>edge[maxn];
vector<int>large;
int n,tot;
void init()
{
  for(int i=0;i<=n;i++)
    edge[i].clear(),mp[i].clear();
    mem(bit,0);
    mem(s,0);
    deep[1]=0;
    tot=0;
    large.clear();
    
}

void dfs(int u,int d)
{
    st[u]=++tot;
     mp[d].pb(st[u]);
    for(auto v:edge[u])
    {
        deep[v]=deep[u]+1;
       
        dfs(v,d+1);
    }
    ed[u]=tot;
}
int lowbit(int x){
return x&(-x);
}
ll sum(int x){
  ll ret=0;
  while(x>0){
    ret+=bit[x];
    x-=lowbit(x);
  }
return ret;
}

void add(int x,ll d){
    if(x<0) return;
   while(x<=n){
    bit[x]+=d;
    x+=lowbit(x);
   }
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int q;
  while(scanf("%d%d",&n,&q)==2)
  {
      init();
      for(int i=1;i<n;i++)
      {
          int a,b;
          scanf("%d%d",&a,&b);
          edge[a].pb(b);
      }
      dfs(1,0);
      for(int i=1;i<=n;i++)
        if(mp[i].size()>block)
            large.pb(i);
        
      for(int i=1;i<=q;i++)
      {
          int op;
          scanf("%d",&op);
          if(op==1)
          {
              int l,x;
              scanf("%d%d",&l,&x);
              if(mp[l].size()<=block)
              {
                  for(auto v:mp[l])
                    add(v,x);
              }
              else s[l]+=x;
          }
          else
          {
              int x;
              scanf("%d",&x);
              int l=st[x];int r=ed[x];
              ll ans=sum(r)-sum(l-1);
              for(auto y:large)
                  ans+=(upper_bound(mp[y].begin(),mp[y].end(),r)-lower_bound(mp[y].begin(),mp[y].end(),l))*s[y];
           printf("%lld\n",ans);          
           }
      }
  }
 return 0;
  }
