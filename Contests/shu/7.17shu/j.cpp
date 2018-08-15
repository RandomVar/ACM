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
const int maxn=1e5+100;

const ll mod=1e9+7;
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll quick[maxn];
void init()
{
    quick[0]=1;
    for(int i=1;i<maxn;i++)
      quick[i]=(quick[i-1]*2)%mod;
}

ll b[maxn];
ll sum[maxn];
char s[maxn];

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n;
   init();
   while(scanf("%lld",&n)==1)
   {
       scanf("%s",s);
       int len=strlen(s);
  
       ll x=0;
       ll ans=1;
      
       for(int i=len-1;i>=0;i--)
       {
           if(s[i]=='1') {b[len-i-1]=1;}
           else b[len-i-1]=0; 
       }
       sum[len]=n-len;

       for(int i=len-1;i>=0;i--)
       {
           sum[i]=sum[i+1]+(b[i]==1?0:1);
           
       }
      
       for(int i=0;i<n;i++){
            if(b[i]){
              if(sum[i]) ans=(ans*(quick[sum[i]]-1+mod)%mod)%mod;
              x+=sum[i];
           }
       }

       x+=sum[0]*(sum[0]-1)/2;

       x=(n*(n-1)/2-x)%mod;
       ans=(ans*quickmod(2,x))%mod;
      printf("%lld\n",ans);
   

   }

 return 0;
  }

