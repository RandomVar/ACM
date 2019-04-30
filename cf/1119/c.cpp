#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int a[maxn][maxn];
int b[maxn][maxn];
int main()
{
  int n,m;
  while(cin>>n>>m)
  {
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>a[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>b[i][j];
    int flag=1;
    for(int i=1;i<=n;i++)
     {
       int sum=0;
       for(int j=1;j<=m;j++)
         if(a[i][j]!=b[i][j]) sum++;
        if(sum%2) flag=0;
     }
     for(int j=1;j<=m;j++)
     {
       int sum=0;
       for(int i=1;i<=n;i++)
         if(a[i][j]!=b[i][j]) sum++;
        if(sum%2) flag=0;
     }
     if(flag) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
  }
}