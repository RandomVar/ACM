#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,k;
   while(scanf("%d%d",&n,&k)==2)
   {
       scanf("%s",s+1);
       for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
          for(int s=0;s<=i;s++)
          {
            if(s[i]=='1')  
             {
               if(s)  dp[i][j][s]=min(dp[i][j][s],dp[i-1][j][s-1]+sum[s]);
               if(j) dp[i][j][0]=min(dp[i][j][s],dp[i-1][j-1][s])
             }
             if(s[i]=='0')
             {
                 dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][s]);
             }
          }
        }
        
   }  
 return 0;
  }

