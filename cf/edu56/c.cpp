#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+100;
ll a[maxn];
ll b[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        n/=2;
        for(int i=1;i<=n;i++)
          scanf("%lld",&b[i]);
        ll st=0;ll en=1e18+10;
        for(int i=1;i<=n;i++)
        {
            ll x=b[i]-st;
          while(x>en)
          {
            x--;
          }
          en=a[2*n-i+1]=x;
          st=a[i]=b[i]-x;
        }
        for(int i=1;i<=2*n;i++)
         printf("%lld ",a[i]);
         printf("\n");
    }
}