#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("a.out","w",stdout);
  int cnt=0;
  long long ans=0;
  int n=101;
  for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=n;j++)
       {
         cnt++;
         if(j<=i+n/2&&j>=i-n/2&&j>=-i+n&&j<=-i+n+(n+1)/2)
          {
            // cout<<cnt<<endl;
            ans+=cnt;
          }
       }
    
   }
      cout<<ans<<endl;
}