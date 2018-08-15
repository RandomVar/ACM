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
int dp[30][20];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;

        for(int i=0;i<s.size();i++){
             for(int v=0;v<=15;v++){
            if(dp[i][v]==-INF) continue;
            dp[i+1][v]=max(dp[i+1][v],dp[i][v]*10+s[i]-'0');
            for(int j=0;j<4;j++){
              if(v&(1<<j)==0)
              {
                  if(j==0)
                   dp[i+1][v|(1<<j)]=max(dp[i+1][v|(1<<j)],dp[i][v]+s[i]-'0');
                   if(j==1)
                     dp[i+1][v|(1<<j)]=max(dp[i+1][v|(1<<j)],dp[i][v]*(s[i]-'0'));
                   if(j==2)
                     dp[i+1][v|(1<<j)]=max(dp[i+1][v|(1<<j)],dp[i][v]-s[i]+'0');
                   if(j==3)
                    if(s[i]!='0') dp[i+1][v|(1<<j)]=max(dp[i+1][v|(1<<j)],dp[i][v]/(s[i]-'0'));
              }
             }
        }
        }
  for(int i=0;i<=15;i++)
    cout<<dp[2][i]<<endl;;
        cout<<dp[s.size()][15];

}}
