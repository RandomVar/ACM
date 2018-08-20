/*
https://www.nowcoder.com/acm/contest/view-submission?submissionId=31951275


*/
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const ll mod=1e9+7;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
ll bit[105][maxn];
ll inv[105];
int n;
int lowbit(int x){
return x&(-x);
}
ll sum(int pos,int x){
  ll ret=0;
  while(x>0){
    ret=(ret+bit[pos][x])%mod;
    x-=lowbit(x);
  }
return ret;
}

void update(int pos,int x,ll d){
    if(x<0) return;
   while(x<=n){
    bit[pos][x]=(bit[pos][x]+d)%mod;
    x+=lowbit(x);
   }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m,k;
   inv[1]=1;
   for(int i=2;i<105;i++)
   inv[i]=inv[mod%i]*(mod-mod/i)%mod;
   while(scanf("%d%d%d",&n,&m,&k)==3)
   {
       k--;
       mem(bit,0);
      for(int i=0;i<m;i++)
      {
          int op;
          scanf("%d",&op);
          if(op==0)
          {
              int a,b;
              scanf("%d%d",&a,&b);
              ll u=1;
              for(int j=0;j<=k;j++)
              {
                  update(j,a,1LL*b*u%mod);
                  u=u*(k-a-j)%mod*inv[j+1]%mod;
                  if(u<0) u+=mod;
              }
          }
          else
          {
              int a;
              scanf("%d",&a);
              ll u=1,z=0;
              for(int j=0;j<=k;j++)
              {
                  z=(z+u*sum(k-j,a))%mod;
                  u=u*(a-j)%mod*inv[j+1]%mod;
              }
              printf("%lld\n",z);
          }
      }
   }
   
 return 0;
  }

