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
const int maxn=2e6+100;
ll a[maxn],b[maxn];


int main(){
  // #ifndef ONLINE_JUDGE
  //    freopen("data.in","r",stdin);
  //     freopen("data.out","w",stdout);
  //    #endif
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
      int n;
      ll c;
      scanf("%d%lld",&n,&c);
      // s[0]=0;
      for(int i=1;i<=n;i++)
       {
         scanf("%lld\n",&a[i]);
         a[i+n]=a[i];
        //  s[i]=s[i-1]+a[i];
       }
       for(int i=1;i<=n;i++)
       {
         scanf("%lld\n",&b[i]);
          b[i+n]=b[i];
       }
       int s=0;int t=0;
      ll now=c;int flag=0;
       while(t-s<n)
       {
         t++;
         now=now+a[t]-b[t];
         while(now<0&&s<t)
           {
             s++;
             now-=a[s]-b[s];
           }
          if(t-s==n) {flag=1;break;}
         if(s>n) break;
       }
       if(flag==0||s+1>n) printf("-1\n");
       else printf("%d\n",s+1);
    }
 return 0;
  }
