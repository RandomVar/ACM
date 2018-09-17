#include<bits/stdc++.h>
using namespace std;
int a[5100];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
         scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int cnt=1;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
          if(a[i]==a[i-1]) cnt++;
         else cnt=1;
         ans=max(ans,cnt);
      }
      if(n==1) printf("1\n");
      else 
      printf("%d\n",ans);
   }
}