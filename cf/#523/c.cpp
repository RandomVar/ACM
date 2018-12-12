#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6+100;
const ll mod=1e9+7;
vector<int>d[maxn];
void init(){
   for(int i=2;i<maxn;i++){
        for(int j=i;j<maxn;j+=i)
        {
            d[j].push_back(i);
        }
      }
}
ll dp[maxn];
int a[maxn];
int main()
{
    int n;
    init();
    //cout<<1<<endl;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
         scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
        
          int len=d[a[i]].size();
          for(int j=len-1;j>=0;j--)
          {
              int x=d[a[i]][j];
              dp[x]=(dp[x]+dp[x-1])%mod;
            //   cout<<x<<" "<<dp[x]<<endl;
          }
            dp[1]=(dp[1]+1)%mod;
         }  
        ll ans=0;
        for(int i=1;i<maxn;i++)
         ans=(ans+dp[i])%mod;
         printf("%I64d\n",ans);     
    }
}