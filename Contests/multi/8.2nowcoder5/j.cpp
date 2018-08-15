#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
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
   ll n,a,b;
   while(cin>>n>>a>>b)
   {
    //   double s1=a*1.0/2.0;
     //  double s2=b*1.0/3.0;
       ll ans=INF;
//cout<<ans<<endl;
           if(n%2==0) ans=n/2*a;
           else if(n>1) ans=min(ans,((n-1)/2-1)*a+b);
          ans=min(ans,(n+1)/2*a);

           if(n%3==0) ans=min(ans,n/3*b);
           if(n%3==1) ans=min(ans,min((n/3+1)*b,n/3*b+a));
           if(n%3==1&&n/3>=1) ans=min(ans,(n/3-1)*b+2*a);
           if(n%3==2) ans=min(ans,min((n/3+1)*b,n/3*b+a));
       cout<<ans<<endl;

   }

 return 0;
  }

