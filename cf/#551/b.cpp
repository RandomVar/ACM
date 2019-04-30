#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
int a[maxn],b[maxn];
int mp[maxn][maxn];
int main()
{
  int n,m,h;
  while(cin>>n>>m>>h)
  {
    for(int i=1;i<=m;i++)
     cin>>a[i];
    for(int i=1;i<=n;i++)
    cin>>b[i];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
       cin>>mp[i][j];
    for(int i=1;i<=n;i++)
    {
      // int flag=0;
      for(int j=1;j<=m;j++)
      {
        if(mp[i][j]==0) continue;
        mp[i][j]=min(a[j],b[i]);
        // if(b[j]<a[i])
        //   {
        //     mp[i][j]=b[j];
        //   }
        // else if(b[j]==a[i])
        // {
        //   mp[i][j]=b[j];
        //   flag=1;
        // }
        // else if(b[j]>a[i])
        // {
        //   mp[i][j]=a[i];
        //   flag=1;
        // }
      }
    }
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=m;j++)
      cout<<mp[i][j]<<" ";
     cout<<endl;
    }
  }
}