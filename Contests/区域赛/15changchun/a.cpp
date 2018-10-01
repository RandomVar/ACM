/*
https://www.cnblogs.com/ACMFish/p/7222822.html

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int g[]={1,5,10,20,50,100,200,500,1000,2000};
int daan;
int c[11];
void dfs(int ans,ll res,int pos)
{
  if(res==0)
  {
    daan=min(daan,ans);
   return;
  }
  // cout<<ans<<" "<<res<<" "<<pos<<endl;
  if(pos==-1) return;
 int x;
   x=min(c[pos],int(res/g[pos]));
  dfs(ans+x,res-1LL*x*g[pos],pos-1);
  if(x>0)
    dfs(ans+x-1,res-1LL*(x-1)*g[pos],pos-1);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    ll p;
    scanf("%lld",&p);
   ll sum=0;
   daan=1e9;int zong=0;
    for(int i=0;i<10;i++)
      scanf("%d",&c[i]),sum+=1LL*g[i]*c[i],zong+=c[i];
      // cout<<zong<<endl;
  ll res=sum-p;
  if(res>=0)
    dfs(0,res,9);
  if(daan==1e9) printf("-1\n");
  else printf("%d\n",zong-daan);
  }
  return 0;
}
