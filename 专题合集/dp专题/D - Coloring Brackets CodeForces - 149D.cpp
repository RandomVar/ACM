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
const int mod=1e9+7;
const int maxn=750;
ll dp[maxn][maxn][5][5];
int g[maxn];
void dfs(int s,int t){
  if(s+1==t){
      dp[s][t][0][1]= dp[s][t][0][2]= dp[s][t][1][0]= dp[s][t][2][0]=1;
      return ;
  }
  if(g[s]==g[t]){
    dfs(s+1,t-1);
    for(int i=0;i<=2;i++)
      for(int j=0;j<=2;j++){
           if(j!=1)  dp[s][t][0][1]=(dp[s][t][0][1]+dp[s+1][t-1][i][j])%mod;
           if(i!=1)  dp[s][t][1][0]=(dp[s][t][1][0]+dp[s+1][t-1][i][j])%mod;
           if(j!=2)  dp[s][t][0][2]=(dp[s][t][0][2]+dp[s+1][t-1][i][j])%mod;
           if(i!=2)  dp[s][t][2][0]=(dp[s][t][2][0]+dp[s+1][t-1][i][j])%mod;

    }
    return ;
  }
  dfs(s,g[s]);
  dfs(g[s]+1,t);

  for(int i=0;i<=2;i++)
     for(int j=0;j<=2;j++)
        for(int k=0;k<=2;k++)
           for(int e=0;e<=2;e++)
           {
               if(k==0||k!=e)
            dp[s][t][i][j]=(dp[s][t][i][j]+dp[s][g[s]][i][k]*dp[g[s]+1][t][e][j])%mod;
      // if(i!=0) dp[s][t][i][j]=(dp[s][t][i][j]+(dp[s][g[s]][i][0]*dp[g[s]+1][t][1][j])%mod+(dp[s][g[s]][i][0]*dp[g[s]+1][t][2][j])%mod)%mod;
      // if(j!=0) dp[s][t][i][j]=(dp[s][t][i][j]+(dp[s][g[s]][i][1]*dp[g[s]+1][t][0][j])%mod+(dp[s][g[s]][i][2]*dp[g[s]+1][t][0][j])%mod)%mod;
      //  dp[s][t][i][j]=(dp[s][t][i][j]+(dp[s][g[s]][i][1]*dp[g[s]+1][t][2][j])%mod+(dp[s][g[s]][i][2]*dp[g[s]+1][t][1][j])%mod)%mod;
  }

}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  string s;
  while(cin>>s){
        mem(g,0);
       mem(dp,0);
        int len=s.size();
    stack<int>st;
    for(int i=0;i<len;i++){
       if(s[i]=='(') st.push(i);
       else {
            int t=st.top();
            st.pop();
           g[i]=g[t]=i;
       }
    }
    dfs(0,len-1);
    ll ans=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          ans=(ans+dp[0][len-1][i][j])%mod;
   cout<<ans<<endl;


  }



return 0;
}
