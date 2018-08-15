#include<bits/stdc++.h>
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
const int maxn=1e6+100;
ll sum[maxn],a[maxn],g[maxn];
ll dp[maxn];
vector<ll>v;
int p[maxn],pre[maxn];
int getid(ll x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
         cin>>a[i],v.push_back(a[i]);
         sort(v.begin(),v.end());
         v.erase(unique(v.begin(),v.end()),v.end());
         mem(p,0);
         for(int i=1;i<=n;i++)
         {
           a[i]=getid(a[i]);
           pre[i]=p[a[i]];
           p[a[i]]=i;
         }
           sum[0]=0;
        for(int i=1;i<=n;i++)
        {
          cin>>g[i];
          sum[i]=sum[i-1]+g[i];
        }
        //mem(ans,-0x3f);
        ll daan=0;
        dp[0]=0;
         for(int i=1;i<=n;i++)
         {
             dp[i]=dp[i-1];
             int x=pre[i];
             while(x>0)
             {
                 if(dp[i]-dp[x-1]>=sum[i]-sum[x-1])
                    break;
                  dp[i]=max(dp[i],dp[x-1]+sum[i]-sum[x-1]);
                    x=pre[x];
             }
           
            daan=max(daan,dp[i]);
          }
         
         cout<<daan<<endl;

    }
    return 0;
}