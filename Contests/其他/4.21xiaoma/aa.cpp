#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int a[maxn];
int main()
{
   int n,h;
   while(cin>>n>>h)
   {
     for(int i=1;i<=n;i++)
     cin>>a[i];
     int ans=0;
    //  cout<<0<<endl;
    for(int i=1;i<=n;i++)
    {
      int j;
    for(j=i-1;j>0;j--)
    {
      if((h-a[i])*(i-j)<=i*(a[j]-a[i]))
      {
        cout<<j<<endl;
        break;
      }
    }
    if(j==0) cout<<0<<endl;
    }
   } 
}