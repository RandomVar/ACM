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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n,m;
   while(cin>>n>>m)
   {
       if(m==1) {cout<<n<<endl;continue;}
       else if(n==1) {cout<<1<<endl;continue;}
       ll ans=0;
       ll i=2;
       while(i<=n)
       {
         //  cout<<i<<endl;
        if(ans+m>=i) {ans=(ans+m)%i;i++;continue;}
        else{
            ll x;
            if((i-1-ans)%(m-1)==0)
               x=(i-1-ans)/(m-1)-1;
            else x=(i-1-ans)/(m-1);
            if(i+x>n) {
                ans += (n-(i-1))*m;
                break;
            }
            ans+=x*m;
            i+=x;
        }
       }
       cout<<ans+1<<endl;
   }
 return 0;
  }
