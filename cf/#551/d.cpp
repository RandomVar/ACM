#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+100;
int ye[maxn];
int f[maxn],p[maxn];
vector<int>edge[maxn];
int fu[maxn];
int cnt;
int dfs(int x)
{ 
  // if(edge[x].size()==0) return 1;
  int ans=0;
  int mm=0x3f3f3f3f;
  for(int i=0;i<edge[x].size();i++)
  {
    int e=edge[x][i];
    int c;
    if(edge[e].size()==0)
      c=1;
   else c=dfs(e);
    mm=min(mm,c);
    ans+=c;
  }
  // if(f[x]==0) ans-=mm;
  if(f[x]) ans=mm;
  return ans;
}
int main()
{
  int n;
  while(cin>>n)
  {
    cnt=0;
    for(int i=1;i<=n;i++)
     cin>>f[i];
     int cnt=0;
    for(int i=2;i<=n;i++)
    {
      cin>>p[i];
      edge[p[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
     if(edge[i].size()==0) cnt++;
    cout<<cnt-dfs(1)+1<<endl;

  }
}