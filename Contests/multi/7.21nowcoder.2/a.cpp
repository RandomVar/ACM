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
const int maxn=1e5+100;
ll dp[maxn];
ll sum[maxn];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int q,k;
   while(cin>>q>>k)
   {
       sum[0]=0;
       dp[0]=1;
      for(int i=1;i<k;i++){
        dp[i]=1;
        sum[i]=(sum[i-1]+dp[i])%mod;
      }
       dp[k]=2;
       sum[k]=sum[k-1]+2;
       for(int i=k+1;i<=1e5;i++){
        dp[i]=(dp[i-1]+dp[i-k-1])%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
      //  if(i<=10) cout<<i<<" "<<dp[i]<<endl;
        }

       for(int i=0;i<q;i++)
       {

           int l,r;
           cin>>l>>r;
           cout<<(sum[r]-sum[l-1]+mod)%mod<<endl;
       
       }
   } 
 return 0;
  }

