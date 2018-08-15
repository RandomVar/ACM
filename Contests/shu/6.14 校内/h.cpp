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
const int mod=1e9+7;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll dp[5010][5];
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    memset(dp,0,sizeof(dp));
    if(s[0]!=0) dp[0][(s[0]-'0')%3]=1;

    for(int i=1;i<s.size();i++){
            //cout<<(s[i]-'0')<<endl;
        for(int j=0;j<3;j++){
            if(s[i]!='0'||dp[i-1][(j-(s[i]-'0')%3+3)%3]!=0) dp[i][j]=(dp[i][j]+dp[i-1][(j-(s[i]-'0')%3+3)%3])%mod;
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        }
      if(s[i]!='0') dp[i][(s[i]-'0')%3]+=1;
    }
    int len=s.size()-1;
   /*for(int i=0;i<s.size();i++){
        for(int j=0;j<3;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    ll ans=dp[len][0]%mod;
    cout<<ans<<endl;
  }
return 0;
}
