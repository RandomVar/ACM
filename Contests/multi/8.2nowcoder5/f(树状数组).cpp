/*
依次有n个钻石，每个钻石存在的概率为p[i],大小为h[i]，若h[i]大于现有h，则会交换钻石，求交换次数的期望

e(i)=e(i-1)+p(i)
期望等于之前的期望加上每一个钻石被换的概率

按hi从大到小遍历，树状数组维护大钻石不存在的概率和
p[i]=p[i]*sum(在i前面的大钻石不存在的概率和)
*/


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
const int maxn=1e5+100;
struct node{
   ll p,h;
   int id;
   bool operator<(const node &b)const{
     if(h==b.h)
       return id<b.id;
     return h>b.h;
   }

}s[maxn];
const ll mod=998244353;
int n;
ll tree[maxn];
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int lowbit(int x){
return x&(-x);
}

ll sum(int x){
  ll ret=1;
  while(x>0){
    ret=(ret*tree[x])%mod;
    x-=lowbit(x);
  }
return ret;
}

void update(int x,ll d){
    if(x<0) return;
   while(x<=n){
    tree[x]=(tree[x]*d)%mod;
    x+=lowbit(x);
   }
}
void init()
{
  for(int i=0;i<=n;i++)
   tree[i]=1;
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  // int n;
   while(cin>>n)
   {
     init();
       for(int i=1;i<=n;i++)
         cin>>s[i].p>>s[i].h,s[i].id=i;
      sort(s+1,s+1+n);
      ll inv=quickmod(100,mod-2);
      ll ans=0;
      for(int i=1;i<=n;i++)
      {
        ll k=((sum(s[i].id)*s[i].p)%mod*inv)%mod;
        ans=(ans+k)%mod;
   
        update(s[i].id,(100-s[i].p)*inv%mod);
      }
     cout<<ans<<endl;
        
   }
 
 return 0;
  }

