#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+100;
int a[maxn];
int st[maxn];
int n,h;
int check(int j,int i)
{
  if(a[i]>=h)
  {
    if((a[i]-h)*j>(a[j]-h)*i)
     return 0;
     return 1;
  }
  if(a[i]>=a[j]) return 0;
  if((h-a[i])*(i-j)<=i*(a[j]-a[i])) return 1;//dangzhu
  return 0;
}
signed main()
{
   
   while(scanf("%lld%lld",&n,&h)==2)
   {
     for(int i=1;i<=n;i++)
     scanf("%lld",&a[i]);
     int i=1;
     int top=-1;
     while(i<=n)
     {
      
       while(top>-1&&!check(st[top],i))
       {
         top--;
       }
        if(top==-1) 
         printf("0\n");
        // cout<<0<<endl;
        else
        {
          printf("%lld\n",st[top]);
          // cout<<st[top]<<endl;
        }
       st[++top]=i++;
     }
   } 
}