#include<bits/stdc++.h>
using namespace std;
long long val[20]={9, 8, 9, 9, 5, 7, 4, 2, 2, 4 ,5 ,6 ,7 ,8 ,9 ,3 ,3 ,4 ,5 ,1};
long long dfs(int s,int t)
{
  if(s==t)
   return val[s];
  if(t==s+1)
    return val[s]+val[t];
  long long ans=0;
  for(int i=s+1;i<t;i++)
  {
    ans=max(ans,dfs(s,i-1)*dfs(i+1,t)+val[i]);
  }
  return ans;
}
int main()
{
  freopen("c.out","w",stdout);
  cout<<dfs(0,19)<<endl;
}