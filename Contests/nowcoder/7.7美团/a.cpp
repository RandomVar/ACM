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
const int mod=1e9+7;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
ll dp[110];
int a[110];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
      for(int i=1;i<=n;i++)
        cin>>a[i];
        ll ans=0;
        mem(dp,0);
        //dp[1]=1;
     for(int i=1;i<=n;i++)
        {
         dp[i]=1;
        for(int j=1;j<i;j++){
                 // cout<<(double)j*log(a[i]*1.0)-(double)i*log(a[j]*1.0)<<endl;
           if((double)j*log(a[i]*1.0)>(double)i*log(a[j]*1.0)){

              dp[i]=(dp[j]+dp[i])%mod;
            // cout<<1<<endl;
           }
            }
            ans+=dp[i];
  }
   cout<<ans<<endl;


  }

}
