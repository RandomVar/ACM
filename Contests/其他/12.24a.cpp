#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
   ll x,y,n;
   while(cin>>x>>y>>n){
    ll ans=x+(n-1)*(y-x);
    cout<<ans<<endl;
   }
}
