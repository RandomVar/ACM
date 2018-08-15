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
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=60;
ll sum[maxn],a[maxn];
int dp[maxn][maxn];
int n,k;
void init(){
    sum[0]=0;
 for(int i=1;i<=n;i++)
    sum[i]=sum[i-1]+a[i];
}
int check(ll x){
    mem(dp,0);
    dp[0][0]=1;
  for(int i=0;i<=n;i++)
    for(int j=0;j<k;j++){
       if(dp[i][j])
       for(int f=i+1;f<=n;f++)
      {
          if(((sum[f]-sum[i])&x)==x)
             dp[f][j+1]=1;
       }
}

return dp[n][k];
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while(cin>>n>>k){
    for(int i=1;i<=n;i++)
      cin>>a[i];
    init();
    ll ans=0;
    for(int i=60;i>=0;i--){
        if(check(ans|(1LL<<i))) ans|=(1LL<<i);
    }
    cout<<ans<<endl;

  }


}
