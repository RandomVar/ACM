#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int a[maxn];
int vis[maxn];
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    
   memset(vis,0,sizeof(vis));
   int cur=n;
    // for(int i=1;i<=n;i++)
    // {
    //   vis[a[i]]=1;
    //    int x=cur;
    //    while(vis[x])
    //    {
    //    if(vis[x-1])  cout<<x<<" ";
    //     else cout<<x;
    //      vis[x]=0;
    //      x--;
    //    }
    //    cur=x;
    //  cout<<endl;
    // }
     for(int i=1;i<=n-1;i++)
    {
      if(a[i]==cur)
      {
        cout<<cur<<endl;
        cur--;
      }
      else 
      {
        //vis[a[i]]=1;
        cout<<endl;
      }
    }
    for(int i=cur;i>1;i--)
      cout<<i<<" ";
    if(cur>1) cout<<1<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //   vis[a[i]]=1;
    //    int x=cur;
    //    if(cur==a[i])
    //    {
    //      cout<<cur<<endl;
    //      vis[a[i]]=0;
    //      x--;
    //    }
    //    else
    //    {
    //     while(vis[x])
    //    {
    //    if(vis[x-1])  cout<<x<<" ";
    //     else cout<<x;
    //      vis[x]=0;
    //      x--;
    //    }
    //       cout<<endl;
    //    }
    //    cur=x;
    
    // }
 
  }
}