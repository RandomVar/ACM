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
ll sum[maxn];
ll a[maxn];
ll tree[maxn<<2];
ll seg[maxn<<2];
void pushup(int rt){
 tree[rt]=tree[rt*2]+tree[rt*2+1];
}

void pushdown(int len,int rt){
  if(seg[rt]){
    seg[rt*2]+=seg[rt];
    seg[rt*2+1]+=seg[rt];
    tree[rt*2]+=(len-len/2)*seg[rt];
    tree[rt*2+1]+=len/2*seg[rt];
    seg[rt]=0;
  }
}

void build(int l,int r,int rt){
  seg[rt]=0;
  if(l==r) {
    tree[rt]=sum[l];
    //scanf("%d",&tree[rt]);
    return;}
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}
void update(int l,int r,int L,int R,ll add,int rt){
  if(l>=L&&r<=R) {
    seg[rt]+=add;
    tree[rt]+=(r-l+1)*add;
    return;
  }
  pushdown(r-l+1,rt);
  int mid=(l+r)/2;
  if(L<=mid)
    update(l,mid,L,R,add,rt*2);

  if(R>mid)
    update(mid+1,r,L,R,add,rt*2+1);

  pushup(rt);
}

ll query(int l,int r,int L,int R,int rt){
  if(l>=L&&r<=R){
     return tree[rt];
  }
  ll ans=0;
  pushdown(r-l+1,rt);
  int mid=(l+r)/2;
  if(L<=mid) ans+=query(l,mid,L,R,rt*2);
  if(R>mid) ans+=query(mid+1,r,L,R,rt*2+1);
  return ans;
}
int main(){
/*  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
 *///ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
      sum[0]=0;
      for(int i=1;i<=n;i++)
       scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
       build(1,n,1);
      for(int i=1;i<=q;i++)
      {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
          int b,c;
          scanf("%d%d",&b,&c);
          ll ans=query(1,n,b,c,1);
          if(b>1) ans-=query(1,n,b-1,b-1,1)*(c-b+1);
          printf("%lld\n",ans);
        }
        if(op==2)
        {
          int b;ll c;
          scanf("%d%lld",&b,&c);
          update(1,n,b,n,c-a[b],1);
            a[b]=c;
        }
      }
    }
 return 0;
}
