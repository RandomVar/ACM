#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int a[maxn];
int b[maxn];
int p[100];
int num;
void init()
{
  int pp=1;
  int i=0;
   while(pp<maxn)
   {
     p[i]=pp;
     i++;
     pp*=2;
   }
   num=i;
}
// int cal(int x)
// {
//   int cnt=lower_bound(p,p+)
//   return cnt;
// }
int isnot(int x)
{
  int pos=lower_bound(p,p+num,x)-p;
  if(p[pos]==x) return 0;
  return 1;
}
int cal(int x)
{
  return lower_bound(p,p+num,x)-p;
  
  // int cnt=0;
  // while(x>1)
  // {
  //   cnt++;
  //   x/=2;
  // }
  // return cnt;
}
int main()
{
  int n;
  init();
  while(cin>>n)
  {
    int gcd;
    for(int i=1;i<=n;i++)
    { 
        cin>>a[i];
        if(i==1) gcd=a[1];
        else gcd=__gcd(gcd,a[i]);
    }
    for(int i=1;i<=n;i++)
     a[i]/=gcd;
     int ans=0;
    for(int i=1;i<=n;i++)
    {
      while(isnot(a[i]))
      {
        a[i]/=2;
        ans++;
      }
      b[i]=cal(a[i]);
    }
    sort(b+1,b+1+n);
    int c=(b[(n+1)/2]+b[(n+2)/2])/2;
    for(int i=1;i<=n;i++)
    {
     ans+=abs(b[i]-c);
    }
        cout<<ans<<endl; 
  }
}