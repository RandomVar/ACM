#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1300;
int d[maxn][maxn];
int a,b,k;
int n;
int check(int x)
{
  int cnt=0;
  for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
        if(i==j) continue;
       d[i][j]=min(d[i][j],d[i][a]+d[b][j]+x);
       d[i][j]=min(d[i][j],d[i][b]+d[a][j]+x);
       cnt=max(cnt,d[i][j]);
      }
      return cnt+x<k;
}
signed main()
{

  while(cin>>n)
  {
    int r;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
     cin>>d[i][j];
    cin>>a>>b>>k;
   
    int mm=0;
    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
       d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
        d[i][j]=min(d[i][j],d[j][i]);
       mm=max(mm,d[i][j]);
      }
     r=d[a][b];
     if(a==b)
     {
       if(mm<k)
       cout<<k-mm-1<<endl;
       else cout<<-1<<endl;
       continue;
     }
    if(mm+r<k)
    {
      cout<<(k-mm-1)<<endl;
      continue;
    }
    // if(!check(0))
    // {
    //   cout<<-1<<endl;
    //   continue;
    // }
    int l=0;
    int ans=-1;
    while(l<=r)
    {
      int mid=(l+r)/2;
      if(check(mid)) {l=mid+1;ans=mid;}
      else r=mid-1;
    }
    cout<<ans<<endl;
  }
}