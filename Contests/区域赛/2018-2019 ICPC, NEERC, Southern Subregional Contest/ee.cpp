#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+100;
struct node
{
  int val;int id;
  bool operator<(const node &b)const
  {
    if(val==b.val) return id<b.id;
   return val<b.val;
  }
}p[maxn];
int bit[maxn];
int n;
int lowbit(int x)
{
  return x&(-x);
}
void add(int x,int val)
{
    while(x<=n)
    {
     bit[x]+=val;
     x+=lowbit(x);
    }
}
int sum(int x)
{
  if(x<=0) return 0;
    int res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=lowbit(x);
    }
    return res;
}
ll su[maxn];
void addsum(int x,ll val)
{
    while(x<=n)
    {
     su[x]+=val;
     x+=lowbit(x);
    }
}
ll getsum(int x)
{
  if(x<=0) return 0;
    ll res=0;
    while(x>0)
    {
        res+=su[x];
        x-=lowbit(x);
    }
    return res;
}

int query(int id)
{
  if(id<=0) return 0;
  int l=1;int r=n;int ans=0;
  while(l<=r)
  {

      int mid=(l+r)/2;
      if(sum(mid)<=id)
        l=mid+1,ans=mid;
    else r=mid-1;
  }
  return ans;
}

int main()
{
  int cas;
  scanf("%d",&cas);
  while(cas--)
  {
    int m;ll t;
    scanf("%d%d%lld",&n,&m,&t);
    for(int i=1;i<=n;i++)
     scanf("%d",&p[i].val),p[i].id=i;
    memset(bit,0,(n+10)*sizeof(int));
    memset(su,0,(n+10)*sizeof(ll));

    sort(p+1,p+1+n);
     ll pre=p[1].val;
     ll id=1; int cnt=0;
     for(int i=1;i<=n;)
     {
        while(i<=n&&pre==p[i].val)
        {
          add(p[i].id,1);
          addsum(p[i].id,p[i].val);
          i++;
        }
        int l=0;int r=n;
       int ans=0;
        while(l<=r)
        {
          int mid=(l+r)/2;
          ll x;int cc=sum(mid);int dd;
          if(cc%m==0) dd=query(cc-m);
          else dd=query(cc-cc%m);
          x=getsum(mid)+getsum(dd);
       
          if(x<=t) 
             ans=cc,l=mid+1;
          else r=mid-1;
        // cout<<mid<<" "<<ans<<endl;
        }
        if(ans>cnt)
        {
          cnt=ans;
          id=pre;
        }
        pre=p[i].val;
     }
     printf("%d %lld\n",cnt,id);
   
    }

   
  }