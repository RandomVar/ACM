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
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   int cas=0;
   while(t--)
   {
       ll a,b,l;
       cin>>a>>b>>l;
       cout<<"Case "<<++cas<<": ";
       ll gc=gcd(a,b);
       ll lcm=gc*a*b;
       ll d=gcd(l,lcm);
       if(d==1) {cout<<"impossible"<<endl;continue;}
       ll ans;
       ll gcc=gcd(d,gc);
       if(gcc==1)
         ans=d;
        else ans=d/gcc;
     cout<<ans<<endl;
   }

 return 0;
  }

