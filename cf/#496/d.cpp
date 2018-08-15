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
const int maxn=2*1e5+100;
int a[maxn],pre[maxn],dp[maxn];
int ji[5];
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  string s;
  while(cin>>s){
   int len=s.size();
   a[0]=0;
   mem(pre,0);
   mem(ji,0);
   mem(dp,0);
   for(int i=0;i<len;i++){
       a[i+1]=(a[i]+s[i]-'0')%3;
        pre[i+1]=ji[a[i+1]];
        ji[a[i+1]]=i+1;
   }
   int ans=0;
   for(int i=1;i<=len;i++)
{
    if(pre[i]==0) dp[i]=(a[i]==0)?1:0;
    else if(s[i-1]=='0') dp[i]=ans+1; 
    else dp[i]=max(dp[pre[i]]+1,dp[i-1]);
    ans=max(ans,dp[i]);
  // cout<<dp[i]<<endl;
}
cout<<ans<<endl;

  }


  }

