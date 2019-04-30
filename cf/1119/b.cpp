#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+100;
ll a[maxn];
ll b[maxn];
int h;
int check(int x)
{
  for(int i=1;i<=x;i++)
   b[i]=a[i];
   sort(b+1,b+1+x);
   ll ans=0;
   ll ans2=0;
   for(int i=2;i<=x;i+=2)
     ans+=b[i];
  for(int i=x;i>=1;i-=2)
    ans2+=b[i];
if(x%2)
  ans+=b[x];
  // cout<<x<<" "<<ans<<" "<<ans2<<endl;
  ans=min(ans,ans2);
 return ans<=h;
}
int main()
{
  int n;
  while(cin>>n>>h)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    int l=0;int r=n;
    int ans=0;
    while(l<=r)
    {
       int mid=(l+r)/2;
       if(check(mid))
         {
           l=mid+1;ans=mid;
         }
         else r=mid-1;
    }
    cout<<ans<<endl;
    // int cnt=0;
    // int h1=0;int h2=0;
    // for(int i=1;i<=n;i++)
    // {
    //   if(h1==h2)
    //   {
    //     if(h1+a[i]<=h)
    //     {
    //     cnt++;
    //     h1+=a[i];
    //     }
    //     else break;
    //   }
    //   else if(h1>h2)
    //   {
    //     if(a[i]<=h1-h2)
    //     {
    //       cnt++;
    //       h2=h1;
    //     }
    //     else if(h1+a[i]<=h)
    //     {
    //       cnt++;
    //       h1+=a[i];
    //     }
    //     else break;
    //   }
    // }
    // cout<<cnt<<endl;
  }
}