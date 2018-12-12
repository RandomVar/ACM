#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
 ll n;
 while(cin>>n)
 {
     ll ans=0;
     ll pre=0;
     for(int i=1;i<=n+1;i++)
      {
          pre+=i;
           ans+=pre;
      }
      cout<<ans<<endl;
 }
}