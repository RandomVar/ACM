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
int s[2100];
int vis[2100];
int dp[2100];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int a,n,m;
  while(cin>>a>>n>>m){
        mem(vis,0);
      int l,r;
     for(int i=0;i<n;i++)
        cin>>l>>r,vis[l+1]++,vis[r+1]--;
        mem(s,0x3f);
     for(int i=1;i<=m;i++){
        int x,p;
        cin>>x>>p;
        s[x]=min(s[x],p);
        }

   mem(dp,0x3f);
     int pre=0;
     dp[0]=0;
   for(int i=1;i<=a;i++){
     pre+=vis[i];
     if(pre){
        for(int j=0;j<=i;j++)
          if(dp[j]!=inf&&s[j]!=inf)  dp[i]=min(dp[i],dp[j]+(i-j)*s[j]);

     }
     else{
        dp[i]=dp[i-1];
     }

   }

    if(dp[a]==inf) cout<<-1<<endl;
    else cout<<dp[a]<<endl;
  }
}
