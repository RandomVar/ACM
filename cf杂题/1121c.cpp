#include<bits/stdc++.h>
using namespace std;
const int maxn=1500;
int a[maxn];
int vis[maxn];
int tim[200000];
typedef pair<int,int> P;
int main()
{
  int n,k;
  while(cin>>n>>k)
  {
    for(int i=1;i<=n;i++)
     cin>>a[i];
    priority_queue<int,vector<int>,greater<int> >que;
    int i=1;
    for(i=1;i<=k;i++)
    {
      vis[i]=0;
      que.push(a[i]);
    }
    int cnt=0;
    tim[0]=cnt;
    int end=0;
    while(!que.empty())
    {
      int p=que.top();
      que.pop();
      tim[p]=++cnt;
      end=max(end,p);
    
    if(i<=n)
    {
      vis[i]=p;
      que.push(p+a[i]);
    }
      i++;   
    }
    int ans=0;
    for(int i=1;i<=end;i++)
     tim[i]=max(tim[i],tim[i-1]);
    // cout<<"tim[50]"<<" "<<tim[50]<<endl;
    for(int i=1;i<=n;i++)
    {
      // cout<<i<<"!!"<<vis[i]<<" "<<tim[vis[i]]<<endl;
      for(int now=vis[i];now<vis[i]+a[i];now++)
      {
        if(now==0) continue;
      if(now-vis[i]+1==int(100*tim[now]*1.0/n+0.5))
        {
          // cout<<i<<" "<<now-vis[i]+1<<endl;
          ans++;break;
        }
      }
    }

   cout<<ans<<endl;
  }
}