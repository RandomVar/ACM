#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
int main(){
  int t;cin>>t;
  while(t--){
      ll n;cin>>n;
        ll ans=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            int cnt=0;
            while(n!=1&&n%i==0){n/=i;cnt++;}
        ans*=cnt*2+1;
        }

    }
    if(n>1) ans*=3;
    cout<<(ans+1)/2<<endl;
  }
}
