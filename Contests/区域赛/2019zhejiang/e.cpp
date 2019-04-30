#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int a[maxn];
vector<int>vec;
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      int x;
     scanf("%d",&a[i]);
    }
    int mx=a[1];
    int ans=0;int result=0;
    for(int i=2;i<=n;i++)
    {
       if(a[i]<mx)
       {
         if(a[i]>ans)
          {
            ans=a[i];
            result=1;
          }
          else if(a[i]==ans)
          {
            result++;
          }
       }
       mx=max(a[i],mx);
    }
    for(int i=1;i<=n;i++)
    {
      if(a[i]<ans)
       result++;
    }
    printf("%d\n",result);
  
  }
}