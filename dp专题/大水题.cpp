/*
https://www.nowcoder.com/acm/contest/159/C
*/
#include<bits/stdc++.h>
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
const int maxn=1e6+100;
ll sum[maxn],a[maxn],g[maxn];
ll dp[maxn];
vector<ll>v;
ll ans[maxn];
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
         for(int i=1;i<=n;i++)
           a[i]=getid(a[i]);
           sum[0]=0;
        for(int i=1;i<=n;i++)
        {
          cin>>g[i];
          sum[i]=sum[i-1]+g[i];
        }
        mem(ans,-0x3f);
        ll daan=0;
        dp[0]=0;
         for(int i=1;i<=n;i++)
         {
             dp[i]=dp[i-1];

            dp[i]=max(dp[i],ans[a[i]]+sum[i]);
            ans[a[i]]=max(ans[a[i]],dp[i-1]-sum[i-1]);
            daan=max(daan,dp[i]);
        }
         
         cout<<daan<<endl;

    }
    return 0;
}