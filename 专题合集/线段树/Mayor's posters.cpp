#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e4+100;
int tree[maxn<<4];
bool vis[maxn];
vector<int>v;
struct node{
    int l,r;
}s[maxn];
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void pushdown(int rt)
{
    if(tree[rt]==-1) return;
    tree[rt*2]=tree[rt*2+1]=tree[rt]; 
}

void pushup(int rt)
{
   if(tree[rt*2]==-1||tree[rt*2+1]==-1)
     {
      tree[rt]=-1;
       return;
       }
    if(tree[rt*2]!=tree[rt*2+1])
      {tree[rt]=-1;return;}
    
    tree[rt]=tree[rt*2];

}
void build(int l,int r,int rt)
{
    tree[rt]=0;
    if(l==r)
        return;

   int mid=(l+r)/2;
   build(l,mid,rt*2);
   build(mid+1,r,rt*2+1);
}
void update(int l,int r,int L,int R,int val,int rt)
{
    if(l>=L&&r<=R)
    {
        tree[rt]=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(L<=mid) update(l,mid,L,R,val,rt*2);
    if(R>mid) update(mid+1,r,L,R,val,rt*2+1);
    pushup(rt);
}
void query(int l,int r,int rt)
{
    if(tree[rt]!=-1)
    {
      vis[tree[rt]]=1; 
     return;
    }

    int mid=(l+r)/2;
   query(l,mid,rt*2);
   query(mid+1,r,rt*2+1);

}
int main(){

 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n;
       scanf("%d",&n);
       v.clear();
       for(int i=1;i<=n;i++)
       {
           scanf("%d%d",&s[i].l,&s[i].r);
           v.pb(s[i].l);v.pb(s[i].r);v.pb(s[i].r+1);
       }
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      int m=v.size();
      build(1,n,1);
      for(int i=1;i<=n;i++)
      {
          update(1,m,getid(s[i].l),getid(s[i].r),i,1);
      }
      mem(vis,0);
      query(1,n,1);
      int ans=0;
      for(int i=1;i<=n;i++)
      {
          if(vis[i])
            ans++; 
      }
      printf("%d\n",ans);

   }
 return 0;
  }
