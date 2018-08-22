/*
对于每个长度为m的连续子区间，求出区间a的最大值以及从左往右扫描该区间时a的最大值的变化次数

就一个简单的单调队列，从后往前扫就好了
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
const int maxn=1e7+100;
ll a[maxn];
ll que[maxn];
ll b[maxn],c[maxn];
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       ll n,m,k,p,q,r,mod;
       scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&m,&k,&p,&q,&r,&mod);
       for(int i=1;i<=k;i++)
         scanf("%lld",&a[i]);
        for(int i=k+1;i<=n;i++)
          a[i]=(p*a[i-1]+q*i+r)%mod;
        int top=-1;
        int s=0;
        for(int i=n;i>=n-m+1;i--)
        {
           while(top>=0&&a[i]>=a[que[top]])
               top--;
            
           que[++top]=i;
        }
        b[n-m+1]=a[que[s]];
        c[n-m+1]=top+1;
        for(int i=n-m;i>=1;i--)
        {
            if(que[s]==i+m) s++;
            while(top>=s&&a[i]>=a[que[top]])
              top--;
            que[++top]=i;
            c[i]=top-s+1;
            b[i]=a[que[s]];
        }
        ll A=0,B=0;
        // for(int i=1;i<=n;i++)
        //  cout<<a[i]<<" ";
        //  cout<<endl;
        for(int i=1;i<=n-m+1;i++)
        {
            B=B+(c[i]^i);
            A=A+(b[i]^i);
           // cout<<c[i]<<" "<<b[i]<<endl;
        }
        printf("%lld %lld\n",A,B);
   }

 return 0;
  }

