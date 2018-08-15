#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e5+10;
int dp[1010][20];
int main(){
    int t;cin>>t;
   int n,d;
   while(t--){
        cin>>n>>d;
        memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
        cin>>dp[i][1];
   int ans=0;
    for(int i=1;i<=n;i++){
      if (1>=n-d&&dp[i][1]==0) ans++;
        for(int j=2;j<=i;j++){
           if(dp[i-1][j-1]!=-1)  {
                dp[i][j]=dp[i][1]^dp[i-1][j-1];
                 if(j>=n-d&&dp[i][j]==0)  {ans++;cout<<i<<" "<<j<<endl;}
    }
   }
   }
   //dp[i][j][k]=dp[i-1][j][k],dp[i-1][j-1][k^a[i]]
   if(n<=d) ans++;
  cout<<ans<<endl;

}}
