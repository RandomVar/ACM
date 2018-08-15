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
int dp[110][110],a[110];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;int cas=0;
  while(t--){
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
        cin>>a[i];
        mem(dp,0x3f);
        for(int i=1;i<=n;i++)
            dp[i][i]=1,dp[i][i-1]=0;
     for(int j=1;j<n;j++)
        for(int i=1;i+j<=n;i++){
            if(a[i]==a[i+j]) dp[i][j+i]=dp[i][i+j-1];

            for(int k=i;k<i+j;k++)
               if(dp[i][k]!=inf&&dp[k+1][i+j]!=inf)
                 dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]);
            /*if(a[i]==a[i+1]) dp[i][i+j]=min(dp[i][i+j],dp[i+1][i+j]);
            ifa[i+j]==a[i+j-1]) dp[i][i+j]=min(dp[i][i+j],dp[i][i+j-1]);
            if(a[i]==a[i+j])
               dp[i][i+j]=min(dp[i][i+j],dp[i+1][i+j-1]+1);
            dp[i][i+j]=min(dp[i][i+j],dp[i+1][i+j-1]+2);
            dp[i][i+j]=min(dp[i][i+j],dp[i][i+j-1]+1);
            dp[i][i+j]=min(dp[i][i+j],dp[i+1][i+j]+1);
*/
     }
     cout<<"Case "<<++cas<<": ";
         cout<<dp[1][n]<<endl;
  }


}
