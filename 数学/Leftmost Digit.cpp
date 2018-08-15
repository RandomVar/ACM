#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;

int main(){
 int t;cin>>t;
 while(t--){
    ll n;
     cin>>n;
   /*  double x;
     x=n*(log10((double)n));
     x-=(ll)x;
     x=pow(10,x);
     ll ans=(ll)x;*/
    ll dig=(ll)n*log10(n);
    //cout<<dig<<endl;
    double ans=(double)n*log10((double)n)-dig;
    //cout<<ans<<endl;
    ans=pow(10,ans);

    cout<<(ll)ans<<endl;
 }
}
