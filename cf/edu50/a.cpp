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
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n,k;
  while(cin>>n>>k)
  {
    //   cout<<k/n<<endl;
      if(k%n==0) cout<<k/n<<endl;
      else cout<<k/n+1<<endl;
  }
 return 0;
  }

