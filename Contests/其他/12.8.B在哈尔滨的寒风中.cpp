#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;

int main(){
  ll n,m;
  while(cin>>n>>m){
    ll ans;
    if(n<=1||m<=1) ans=0;
    else if(n==2&&m==2) ans=0;
    else if(n==2||m==2){ll a=max(n,m);//int t1=a-2;
    //ans=t1*(t1-1)+(t1/2*2)*(t1/2*2-1);
    ans=(a/2)*(a/2-1)+(a-a/2)*(a-a/2-1);
    }
    else if(n==3&&m==3) ans=8*7/2;
    else if(n>=3&&m>=3) { ans=(n*m)*(n*m-1)/2;}
   cout<<ans<<endl;
  }
  return 0;
}
