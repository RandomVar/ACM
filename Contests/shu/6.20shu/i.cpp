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
const int maxn=2600;
ll dp[30][maxn][50];
const int mod=2520;
int bit[30];
int h[maxn];
ll gcd(ll a,ll b){
         if(a < b){
                   swap(a,b);
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}
ll lcm(ll a,ll b){
return a/gcd(a,b)*b;

}
void init(){
   int cnt=0;
   for(int i=1;i<=mod;i++)
     if(mod%i==0)
       h[i]=++cnt;
}
ll dfs(int pos,int premod,int prelcm,bool flag){
   if(pos==0) return premod%prelcm==0;
   if(flag&&~dp[pos][premod][h[prelcm]])
     return dp[pos][premod][h[prelcm]];
   int u=flag?9:bit[pos];
   ll ans=0;
   int nextmod,nextlcm;
   for(int d=0;d<=u;d++){
    nextmod=(premod*10+d)%mod;
    nextlcm=prelcm;
    if(d) nextlcm=lcm(prelcm,d);
    ans+=dfs(pos-1,nextmod,nextlcm,flag||d<u);

   }
   if(flag) dp[pos][premod][h[prelcm]]=ans;
   return ans;
}
ll solve(ll n){
    int len=0;
    while(n>0){
        bit[++len]=n%10;
        n/=10;
    }
return dfs(len,0,1,0);
}
int main(){
   int t;
   scanf("%d",&t);
   init();
   memset(dp,-1,sizeof(dp));
   while(t--){
       ll l;ll r;
       scanf("%lld%lld",&l,&r);
       ll ans=solve(r)-solve(l-1);
       printf("%lld\n",ans);

   }
return 0;
}
