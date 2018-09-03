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
int dp[110][110];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  string s;
  while(cin>>s){
        if(s=="end") break;
        int len=s.size();
        mem(dp,0);
  int ans=0;
   for(int j=1;j<len;j++)
    for(int i=0;i+j<len;i++)
       {
           if((s[i]=='('&&s[i+j]==')')||(s[i]=='['&&s[i+j]==']'))
              dp[i][i+j]=max(dp[i][i+j],dp[i+1][i+j-1]+2);
          else dp[i][i+j]=max(dp[i+1][i+j],dp[i][i+j-1]);
          for(int k=i+1;k<i+j;k++)
            for(int f=k+1;f<i+j;f++)

                dp[i][i+j]=max(dp[i][i+j],dp[i][k]+dp[f][i+j]);
          ans=max(ans,dp[i][i+j]);
       }

        cout<<ans<<endl;

  }


}
