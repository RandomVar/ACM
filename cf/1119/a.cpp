#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+100;
int a[maxn];
int main()
{
  int n;
  while(cin>>n)
  {
    int ans=0;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    if(a[1]!=a[n])
     {
       cout<<n-1<<endl;
       continue;
     }
     else
     {
    for(int i=1;i<=n;i++)
     {
       if(a[i]!=a[1])
       {
         ans=max(ans,i-1);
         ans=max(ans,n-i);
       }  
     }
     cout<<ans<<endl;
     }
  }
}