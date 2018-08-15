#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
char s[510][510];
int dp[510][510];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;int k=0;
   while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
        mem(dp);
    for(int i=1;i<=n;i++){
      for(int j=0;j<m;j++){
        if(s[i][j]=='0'){
            dp[i][j]=dp[i-1][j];
        }
        else{
            dp[i][j]=dp[i-1][j]+1;
            if(j&&s[i][j-1]=='1') dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
      }
      for(int j=m-1;j>=1;j--){
        if(s[i][j]=='1'&&s[i][j-1]=='1'){
            dp[i][j-1]=max(dp[i][j],dp[i][j-1]);
        }
      }
    }
    int ans=0;
    for(int j=0;j<m;j++)
        ans=max(ans,dp[n][j]);
    cout<<"Case #"<<++k<<":"<<endl;
    cout<<ans<<endl;
   }
}
