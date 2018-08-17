/*
*确定左端点和右端点，货物被移到第[中位数]个货物所在的地方是最优的
*一个集装箱的货物可以不被移完

二分答案check
check的时候确定左端点 o(n)扫一遍，根据中位数和右端点的单调递增，爆炸计算
由于一个集装箱的货物可以不被移完，需要左扫一遍右扫一遍

*爆炸代码居然能对，阿弥陀佛

*/
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
const int maxn=5*1e5+100;
struct node{
    ll a,x;
}s[maxn];

ll num[maxn],sum[maxn];
int n;

int check(ll shu,ll lim)
{
   
    int zhong=1;int zong=1;
    for(int i=1;i<=n;i++)
    {
        while(zhong<=n&&num[zhong]-num[i-1]<(shu+1)/2)
         zhong++;
         while(zong<=n&&num[zong]-num[i-1]<shu)
          zong++;
          if(num[zong]-num[i-1]<shu) break;
          ll res=num[zong]-num[i-1]-shu;//unused zong
          ll you=num[zong]-num[zhong]-res;
        //   cout<<zong<<" "<<num[zong]<<" "<<num[i-1]<<endl;
        //   cout<<res<<" "<<you<<endl;
        ll c=s[zhong].x*(shu-you)-(sum[zhong]-sum[i-1])+(sum[zong]-res*s[zong].x-sum[zhong])-s[zhong].x*you;
        // cout<<shu<<" "<<i<<" "<<c<<" "<<lim<<endl;
        if(2*c<=lim) return 1;
        if(zhong>1) zhong--;
        if(zong>1) zong--;
    }
    zhong=n;zong=n;
    for(int i=n;i>=1;i--)
    {
        while(zhong>=1&&num[i]-num[zhong-1]<(shu+1)/2)
         zhong--;
         while(zong>=1&&num[i]-num[zong-1]<shu)
          zong--;
          if(num[i]-num[zong-1]<shu) return 0;
          ll res=num[i]-num[zong-1]-shu;//unused zong
          ll zuo=num[zhong]-num[zong-1]-res;
        // cout<<zong<<" "<<zhong<<endl;
        //   cout<<res<<" "<<zuo<<endl;
        ll c=s[zhong].x*zuo-(sum[zhong]-sum[zong-1]-res*s[zong].x)+sum[i]-sum[zhong]-s[zhong].x*(shu-zuo);
        // ll c=s[zhong].x*(shu-you)-(sum[zhong]-sum[zong-1])+(sum[i]-res*s[i].x-sum[zhong])-s[zhong].x*you;
     // cout<<shu<<" "<<i<<" "<<c<<" "<<lim<<endl;
        if(2*c<=lim) return 1;
        if(zhong<n) zhong++;
        if(zong<n) zong++;
    }
  return 0;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll t;
   while(scanf("%d%lld",&n,&t)==2)
   {
    for(int i=1;i<=n;i++)
     scanf("%lld",&s[i].x);
     for(int i=1;i<=n;i++)
      scanf("%lld",&s[i].a);
     
     num[0]=sum[0]=0;
    for(int i=1;i<=n;i++)
      {
          sum[i]=sum[i-1]+s[i].x*s[i].a;
          num[i]=num[i-1]+s[i].a;
      }

    ll l=0;ll r=5e9+10;
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid,t))
          l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%lld\n",ans);
   
   }
 return 0;
  }

