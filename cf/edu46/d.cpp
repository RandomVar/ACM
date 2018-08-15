#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e3+100;
ll c[maxn][maxn];
ll dp[maxn];
ll a[maxn];
void init(){
 for(int j=0;j<=1000;j++)
        c[0][j]=1;
  for(int i=1;i<=1000;i++)
    for(int j=0;j<=1000;j++)
  {
     if(i==j) c[i][j]=1;
     else if(j<i) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i][j-1])%mod;
     // cout<<j<<" "<<i<<" "<<c[i][j]<<endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  init();
  while(cin>>n){
     for(int i=1;i<=n;i++)
        cin>>a[i];
    mem(dp,0);
    dp[n+1]=1;
    ll ans=0;
     for(int i=n;i>=1;i--){
        if(a[i]>0) {
        for(int j=i+a[i]+1;j<=n+1;j++)
          dp[i]=(dp[i]+(dp[j]*c[a[i]][j-i-1])%mod)%mod;
         ans=(ans+dp[i])%mod;
     }}

      cout<<ans<<endl;
  }

return 0;
}
