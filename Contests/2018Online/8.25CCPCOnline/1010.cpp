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
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
struct node{
    ll x,y,v;
    bool operator<(const node &b)
    {
        if(x==b.x)
            return y>b.y;
        return x<b.x;
    }
}a[maxn];
vector<ll>v;
ll bit[maxn];
int m;
int lowbit(int x){
return x&(-x);
}
ll sum(int x){
  ll ret=0;
  while(x>0){
    ret=max(ret,bit[x]);
    x-=lowbit(x);
  }
return ret;
}

void add(int x,ll d){
    if(x<0) return;
   while(x<=m){
    bit[x]=max(bit[x],d);
    x+=lowbit(x);
   }
}
int id(ll x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        int n;
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        a[0].x=0;a[0].y=0;a[0].v=0;
        v.pb(0);
        for(int i=1;i<=n;i++)
         scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v),v.pb(a[i].y);
        sort(a+1,a+1+n);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        m=v.size();
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=id(a[i].y);
            ll p=sum(x-1)+a[i].v;
            ans=max(ans,p);
            add(x,p);
        }
       printf("%lld\n",ans);
    }
 return 0;
  }
