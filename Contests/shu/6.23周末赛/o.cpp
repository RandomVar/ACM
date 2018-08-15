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
int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      ll ans=1;
      for(int i=1;i<=n;i++)
      {
          ll t;
          cin>>t;
          ans=lcm(ans,t);
      }
      cout<<ans<<endl;

   }
}
