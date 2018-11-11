#include<bits/stdc++.h>
#define ll long long
using namespace std;
int getbit(ll x)
{
    int cnt=0;
  for(int i=0;i<63;i++)
    if((x>>i)&1) cnt++;

return cnt;
}
const int maxn=3e5+100;
int a[maxn];
ll sum[maxn];
int bit[maxn];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x)
{
    while(x<=n)
    {
        bit[x]++;
        x+=lowbit(x);
    }
}
int su(int x)
{
    int res=0;
    while(x>0)
    {
      res+=bit[x];
      x-=lowbit(x);
    }
    return res;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        ll ans=0;ll x;
        for(int i=1;i<=n;i++)
        {
         scanf("%lld",&x);
         a[i]=getbit(x);
        // cout<<a[i]<<endl;
        }
        sum[0]=0;
        for(int i=1;i<=n;i++)
         {
           sum[i]=sum[i-1]+a[i];
           if(sum[i]%2)
              add(i); 
         }

        for(int i=1;i<=n;i++)
         {
            int ma=a[i];
         for(int j=0;j<=128&&i+j<=n;j++)
         {
            int k=i+j;
            ma=max(a[k],ma);
            if((sum[k]-sum[i-1])/2>=ma&&(sum[k]-sum[i-1])%2==0)
               ans++;
         }
         int x=su(n)-su(min(i+128,n));
         if(sum[i-1]%2) ans+=x;
         else ans+=n-min(n,(i+128))-x;
        //  cout<<x<<" "<<ans<<endl;
         }
     printf("%lld\n",ans);

    }
}