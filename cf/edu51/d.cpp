#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
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
ll dp[1100][5][2100];
const ll mod=998244353;
int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(cin>>n>>m)
   {
     mem(dp,0);
    //  for(int j=0;j<4;j++)
      dp[1][0][1]=dp[1][3][1]=1;
      dp[1][1][2]=dp[1][2][2]=1;

     for(int i=2;i<=n;i++)
     {
       for(int j=0;j<4;j++)
       {
        for(int s=0;s<4;s++)
           for(int k=0;k<=m;k++)
           {
        if(j==s)  dp[i][j][k]=(dp[i][j][k]+dp[i-1][s][k])%mod;
        else if((j==0&&s!=3)||(j==3&&s!=0))
          dp[i][j][k]=(dp[i][j][k]+dp[i-1][s][k])%mod;
        else if((j==1&&s==2)||(j==2&&s==1))
          dp[i][j][k+2]=(dp[i][j][k+2]+dp[i-1][s][k])%mod;
        else
             dp[i][j][k+1]= (dp[i][j][k+1]+dp[i-1][s][k])%mod;
           }
     }
     }
     ll ans=0;
     for(int j=0;j<4;j++)
      ans=(ans+dp[n][j][m])%mod;
      cout<<ans<<endl;
   }
 return 0;
  }
