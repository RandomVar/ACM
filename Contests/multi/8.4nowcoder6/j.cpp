#include<bits/stdc++.h>
using namespace std;
 
#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll unsigned
#define ull unsigned long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
const int maxn=1e7+100;
ll a,b,c;
int n;
ll x,y,z;
ll d[maxn];
ull gcd( ull o, ull p)
{
  return p ==0?o:gcd(p,o%p);
}
ll tang()
{
  ll t;
  x ^= (x<<16);
  x ^= (x>>5);
  x ^= (x<<1);
  t = x;
  x = y;
  y = z;
  z = x^y^t;
  return z;
}
int main()
{
  int t;
  scanf("%d",&t);
  int tot = 0;
  while(t--)
  {
   
    scanf("%d%u%u%u",&n,&a,&b,&c);
    x = a,y = b,z = c;
   
    for(int i = 0;i<n;i++)
      d[i] = tang();
  if(n>20)      
    nth_element(d,d+n-21,d+n);
  else sort(d,d+n);
    ull ans=0;
    for(int i=max(n-21,0);i<n;i++)
      for(int j=i+1;j<n;j++)
      {
        ans=max(ans,(ull)d[i]*d[j]/gcd(d[i],d[j]));
      }
    //maxn = max(maxn,1LL*shu[0][i]/gcd(shu[1][j],shu[0][i])*shu[1][j]);
    printf("Case #%d: ",++tot);
    cout<<ans<<endl;
   // printf("%ull\n",ans);
  }
  return 0;
}