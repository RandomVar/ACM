#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
long long a[maxn],b[maxn],gcd1[maxn],gcd2[maxn],sum1[maxn],sum2[maxn];

int main()
{
  int n;
  while(cin>>n)
  {
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    sort(a,a+n);
    n--;
    for(int i=0;i<n;i++)
      b[i]=a[i+1]-a[i];
    gcd1[0]=b[0];
    sum1[0]=b[0];
    for(int i=1;i<n;i++)
    {
      gcd1[i]=__gcd(b[i],gcd1[i-1]);
      sum1[i]=sum1[i-1]+b[i];
    }
    gcd2[n-1]=b[n-1];sum2[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--)
    {
      gcd2[i]=__gcd(b[i],gcd2[i+1]);
      sum2[i]=sum2[i+1]+b[i];
    }
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<n-1;i++)
    {
      int g=__gcd(gcd1[i-1],gcd2[i+1]);
       ans=min(ans,sum1[i-1]/g+sum2[i+1]/g);
    }
    // cout<<ans<<endl;
    ans=min(ans,sum2[1]/gcd2[1]);
    ans=min(ans,sum1[n-2]/gcd1[n-2]);
    cout<<ans-(n-1)<<endl;
  }
}