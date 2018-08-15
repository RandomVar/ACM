/**
这是一题 dp
*/

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
int dp[2010][2010];
int main(){
   string a;
   string b;
   string c;
   while(cin>>a>>b>>c){
        memset(dp,0,sizeof(dp));
      dp[0][0]=1;
      if(c.size()!=(a.size()+b.size()))
        cout<<"No"<<endl;
      else{
            int i,j;
      for(i=0;i<=a.size();i++){

        for(j=0;j<=b.size();j++){

          if(i<a.size()&&c[i+j]==a[i])
             dp[i+1][j]=dp[i][j];

           if(j<b.size()&&c[i+j]==b[j])
             dp[i][j+1]|=dp[i][j];
        }

       }
       /* for(int i=0;i<=a.size();i++)
            for(int j=0;j<=b.size();j++)
              cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
      */
      if(dp[i-1][j-1]==0) cout<<"No"<<endl;
      else cout<<"Yes"<<endl;
   }
   }

return 0;
}
