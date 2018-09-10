/*
 https://www.nowcoder.com/discuss/90164?type=101&order=0&pos=3&page=1

+ 给定一个 [1,n] 之间所有偶数的排列 b。归并a=[1,3,5…..n-1] 和 b，使得他们归并后逆序对数量最少
     + 分析完即为水题
     + 将b插入序列中，易证$b_{i}$的最优位置一定是递增的，所以只需求出$b_{i}$插入产生的最少逆序对数量即可
     + 线段树节点表示$b_{i}$插入到每个位置所产生的逆序对个数，并用线段树维护逆序对个数的最小值。递推区间更新即可。
*/
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
const int maxn=2e5+1000;
int tree[maxn<<2];
int seg[maxn<<2];
void pushup(int rt){
 tree[rt]=min(tree[rt*2],tree[rt*2+1]);
}

void pushdown(int rt){
  if(seg[rt]){
    seg[rt*2]+=seg[rt];
    seg[rt*2+1]+=seg[rt];
    tree[rt*2]+=seg[rt];
    tree[rt*2+1]+=seg[rt];
    seg[rt]=0;
  }
}
void build(int l,int r,int rt){
  seg[rt]=0;
  if(l==r) {
      tree[rt]=l-1;
    //scanf("%d",&tree[rt]);
    return;
    }
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}
void update(int l,int r,int L,int R,int add,int rt){
  if(l>=L&&r<=R) {
    seg[rt]+=add;
    tree[rt]+=add;
    return;
  }
  pushdown(rt);
  int mid=(l+r)/2;
  if(L<=mid) 
    update(l,mid,L,R,add,rt*2);
  
  if(R>mid)
    update(mid+1,r,L,R,add,rt*2+1);
  
  pushup(rt);
}

int query(int l,int r,int L,int R,int rt){
  if(l>=L&&r<=R){
     return tree[rt];
  }
  int ans=0;
  pushdown(rt);
  int mid=(l+r)/2;
  if(L<=mid) ans+=query(l,mid,L,R,rt*2);
  if(R>mid) ans+=query(mid+1,r,L,R,rt*2+1);
  return ans;
}
int w[maxn];
int bit[maxn];
int a[maxn];
int n;
int lowbit(int x){
return x&(-x);
}
int sum(int x){
  int ret=0;
  while(x>0){
    ret+=bit[x];
    x-=lowbit(x);
  }
return ret;
}

void add(int x){
    if(x<0) return;
   while(x<=n){
    bit[x]++;
    x+=lowbit(x);
   }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   while(scanf("%d",&n)==1)
   {
       for(int i=1;i<=n/2;i++)
       scanf("%d",&a[i]),w[a[i]]=i;
       ll ans=0;
       mem(bit,0);
       for(int i=1;i<=n/2;i++)
       {
          ans+=sum(n+1-a[i]);
           add(n+1-a[i]);
       }
    //    cout<<ans<<endl;
      
       int l=1;int r=n/2+1;
        build(l,r,1);
       for(int i=3;i<=n;i+=2)
       {
           int k=w[i-1];
        //    cout<<k<<endl;
           update(l,r,l,k,1,1);
           update(l,r,k+1,r,-1,1);
           ans+=query(l,r,l,r,1);
       }
       printf("%lld\n",ans);
   }
 return 0;
  }
