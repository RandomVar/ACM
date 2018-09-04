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
typedef unsigned long long ull;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int seed=31;
const int maxn=1e5+100;
int sum[maxn];
map<int,int> cnt[maxn];
int h[maxn];
int sz[maxn];
int  ans[maxn];
int skip[maxn];
vector< pair<int,int> >q[maxn];
// vector<ull>v;
vector<int>edge[maxn];
map<string,int>mp;
// ull c[maxn];
int id[maxn];
/*
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),c[x])-v.begin();
}
*/

void add(int u)
{
    if(cnt[h[u]][id[u]]==0)
     sum[h[u]]++;
     cnt[h[u]][id[u]]++;
     for(auto v:edge[u])
       if(!skip[v]) add(v);
}
void del(int u)
{
    if(cnt[h[u]][id[u]]==1)
      sum[h[u]]--;
     cnt[h[u]][id[u]]--;
     for(auto v:edge[u])
       if(!skip[v]) del(v);
}
void getsz(int u)
{
    sz[u]=0;
    for(auto v:edge[u])
    {
        h[v]=h[u]+1;
        getsz(v);
        sz[u]+=sz[v]+1;
    }
}
void dfs(int u,int keep)
{
    int mx=-1;int bc=-1;
   for(auto v:edge[u])
   {
        if(sz[v]>mx) mx=sz[v],bc=v;
   }
   for(auto v:edge[u])
   {
       if(bc!=v) dfs(v,0);
   }
   if(bc!=-1) skip[bc]=1,dfs(bc,1);
   add(u);
   for(auto v:q[u])
     ans[v.sec]=sum[h[u]+v.fir];//,cout<<v.sec<<" "<<u<<" "<<h[u]<<" "<<sum[h[u]+v.fir]<<endl;

   if(bc!=-1) skip[bc]=0;
   if(keep==0)
     del(u);
}
void init()
{
    h[0]=0;
    mem(sum,0);
    mem(skip,0);
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
        init();
        int k=0;
        for(int i=1;i<=n;i++)
        {
            int r;char s[30];
            scanf("%s%d",s,&r);
            edge[r].pb(i);
            if(mp[s])
              id[i]=mp[s];
            else mp[s]=++k,id[i]=k;
            // int len=strlen(s);
            // for(int j=0;j<len;j++)
                //  c[i]=c[i]*seed+s[j]-'a'+1;
        //    v.pb(c[i]);
        }
        // sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
     
        getsz(0);
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int v,k;
            scanf("%d%d",&v,&k);
            q[v].pb(mkr(k,i));
        }
        dfs(0,0);
        for(int i=1;i<=m;i++)
          printf("%d\n",ans[i]);
    }
 return 0;
  }
