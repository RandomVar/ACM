#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn],d[maxn];
int main()
{
  int n,t;
  while(cin>>n>>t)
  {
    int ans=0x3f3f3f3f;
    int pos=-1;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i]>>d[i];
    }
    for(int i=1;i<=n;i++)
    {
      if(t<=a[i])
      {
        if(a[i]-t<ans)
        {
          ans=a[i]-t;
          pos=i;
        }
      }
        else 
        {
          if((t-a[i])%d[i]==0)
          {
            ans=0;
            pos=i;
          }
          else if(d[i]-(t-a[i])%d[i]<ans)
          {
          ans=d[i]-(t-a[i])%d[i];
          pos=i;
          }
        }
    }
    cout<<pos<<endl;
  }
}