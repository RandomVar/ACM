#include<bits/stdc++.h>
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
const int maxn=2e5+100;
const ll mod=998244353;
ll res;
ll tree[maxn<<2];
int d[maxn];
vector<ll>v;
struct node{
   ll l,r;
   int id;
   
   bool operator<(const node &b)const{
       return l<b.l;
   }
}a[maxn];
 
void pushup(int rt){
 
  tree[rt]=max(tree[rt*2],tree[rt*2+1]);
}
 
void build(int l,int r,int rt){
  if(l==r) {
      tree[rt]=a[l].r;
      //scanf("%d",&tree[rt]);
      return;
      }
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}
 
ll query(int l,int r,int L,int R,ll x,int c,int rt){
  
 if(tree[rt]<x) return 0;
 if(l==r)
 {
       d[a[l].id]=c;
       tree[rt]=-INF;
       res=(res*a[l].id)%mod;    
       return 1;
 }
 ll ans=0;
 int mid=(l+r)/2;
 if(L<=mid){
    ans+=query(l,mid,L,R,x,c,rt*2);
 }
 if(R>mid){
    ans+=query(mid+1,r,L,R,x,c,rt*2+1);
 }
 pushup(rt);
 return ans;
}
 
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;int cas=0;
   scanf("%d",&t);
   while(t--)
   {
       mem(d,0);
       int n,m;
       scanf("%d%d",&n,&m);
       v.clear();
       for(int i=1;i<=n;i++)
       {
           scanf("%lld%lld",&a[i].l,&a[i].r),v.push_back(a[i].l);
           a[i].id=i;
           
       }
       sort(v.begin(),v.end());
       //int N=v.size()+2;
       sort(a+1,a+1+n);
       build(1,n,1);
       res=0;
        printf("Case #%d:\n",++cas);
     for(int i=1;i<=m;i++)
       {
           ll ans=0;
           ll q;
           scanf("%lld",&q);
           q^=res;
           int x=upper_bound(v.begin(),v.end(),q)-v.begin();
           res=1;
           if(x!=0)
              ans=query(1,n,1,x,q,i,1);
           //cout<<"*"<<x<<" "<<q<<endl;
          printf("%lld\n",ans);
         if(ans==0) res=0;
       }
      for(int i=1;i<n;i++)
       printf("%d ",d[i]);
       printf("%d\n",d[n]);
   }
 return 0;
  }