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
int bit[40];
ll dp[40][2][2][10];
ll dfs(int pos,int st,int flag,int lcm){
   if(pos==0&&st==1&&lcm!=0) return 1;
   else if(pos==0) return 0;
   if(flag&&dp[pos][st][flag][lcm]!=-1)
      return dp[pos][st][flag][lcm];
   int u=flag?9:bit[pos];
   ll ans=0;
   for(int i=0;i<=u;i++){
     // if(i==4) continue;
     // else if(st==0&&i==2) continue;
      if(i!=7) ans+=dfs(pos-1,st,flag||i<u,(lcm*10+i)%7);
      else if(i==7) ans+=dfs(pos-1,1,flag||i<u,(lcm*10+i)%7);
   }

  if(flag)
	dp[pos][st][flag][lcm] = ans;
return ans;
}

ll solve(ll n){
  //mem(dp,-1);
  int len=0;
   ll ans=0;
   ans+=n/7;

  while(n){
     bit[++len]=n%10;
     n/=10;
  }

  ans+=dfs(len,0,0,0);

  return ans;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n,m;
  mem(dp,-1);
  while(scanf("%lld%lld",&m,&n)==2){
    ll a1=solve(m);
  //  cout<<a1<<endl;
    ll high=5e8;ll low=m+n-1;
    while(high-low>1){
           // mem(dp,-1);
        ll mid=(high+low)/2;
        ll ans=solve(mid)-a1;
        if(ans>=n) high=mid;
        else low=mid;
    }
    printf("%lld\n",high);
    //cout<<high<<endl;
  }
return 0;
  }

