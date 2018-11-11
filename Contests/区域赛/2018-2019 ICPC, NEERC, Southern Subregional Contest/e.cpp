#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2.5e5+100;
struct node
{
  ll val;int id;
  bool operator<(const node &b)const
  {
    if(val==b.val) return id<b.id;
   return val<b.val;
  }
}p[maxn];
ll bit[maxn];
int c[maxn];
int n,m;ll t;
int lowbit(int x)
{
  return x&(-x);
}
void add(int x,ll val)
{
    while(x<=n)
    {
     bit[x]+=val;
     c[x]++;
     x+=lowbit(x);
    }
}
ll sum(int k)
{
    if(k<=0) return 0;
    ll res=0;
    int p=0;
    for(int x=1<<20;x;x/=2)
    { 
     if(p+x<=n&&c[p+x]<=k)
     {
         p+=x;
         k-=c[p];
         res+=bit[p];
     }
    }
   return res;
}
ll query(int k)
{
    // cout<<"query"<<k<<endl;
    // cout<<"ans"<<sum(k)<<" "<<sum(k-(k%m==0?m:k%m))<<endl;
  return  sum(k)+sum(k-(k%m==0?m:k%m));
}

int main()
{
  int cas;
  scanf("%d",&cas);
  while(cas--)
  {
    scanf("%d%d%lld",&n,&m,&t);
    for(int i=1;i<=n;i++)
     scanf("%lld",&p[i].val),p[i].id=i;
    memset(bit,0,(n+20)*sizeof(ll));
    memset(c,0,(n+20)*sizeof(int));

    sort(p+1,p+1+n);
     ll pre=p[1].val;
     ll id=1; int cnt=0;
     for(int i=1;i<=n;)
     {
        while(i<=n&&pre==p[i].val)
        {
          add(p[i].id,p[i].val);
          i++;
        }
        int l=0;int r=i-1;
       int ans=0;
    //    cout<<"*"<<pre<<endl;
        while(l<=r)
        {
          int mid=(l+r)/2;
         if(query(mid)<=t)
             ans=mid,l=mid+1;
          else r=mid-1;
        // cout<<mid<<" "<<query(mid)<<endl;
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