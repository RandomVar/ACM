/*
https://blog.csdn.net/keshuai19940722/article/details/49583449
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int g[]={0,1,5,10,20,50,100,200,500,1000,2000};
int c[12];
ll s[12];
int daan;
void dfs(ll res,int pos,int ans)
{
  // cout<<res<<" "<<pos<<" "<<ans<<endl;
  if(res<0) return;
  if(res==0)
    {
      daan=max(daan,ans);
      return;
    }
  if(pos==0) return;
  ll tmp=max(0LL,res-s[pos-1]);
  int k=tmp/g[pos]+(tmp%g[pos]?1:0);
  // cout<<"*"<<tmp<<" "<<k<<" "<<res-1LL*k*g[pos]<<endl;
  if(k>c[pos]) return;
  dfs(res-1LL*k*g[pos],pos-1,ans+k);
  k++;
  if(k<=c[pos])
    dfs(res-1LL*k*g[pos],pos-1,ans+k);
}

int main()
{
  #ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
  int t;
  scanf("%d",&t);
  while(t--)
  {
    ll p;
    scanf("%lld",&p);
    s[0]=0;
    for(int i=1;i<=10;i++)
     scanf("%d",&c[i]),s[i]=s[i-1]+1LL*c[i]*g[i];

     daan=-1;
    dfs(p,10,0);
    printf("%d\n",daan);
  }
}
