#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int bit[30];
ll dp[30][30][15];
ll dfs(int pos,int cnt,int pre,int flag)
{
   if(pos==0) return cnt<=3;
   if(flag&&dp[pos][cnt][pre]!=-1)
      return dp[pos][cnt][pre];
   int u=flag?9:bit[pos];
   ll ans=0;
   for(int i=0;i<=u;i++){
  ans+=dfs(pos-1,cnt+(i!=0),i,flag||i<u);
      }
  if(flag)  dp[pos][cnt][pre]=ans; 
return ans;
}
ll solve(ll n){
  int len=0;
  while(n){
     bit[++len]=n%10;//len=1为最低位
     n/=10;
  }
  return dfs(len,0,0,0);
}
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,-1);
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
 return 0;
  }

