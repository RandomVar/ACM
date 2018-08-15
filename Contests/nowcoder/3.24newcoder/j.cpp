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
ll a[100100];
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
   // ll MIN=INF;
    ll MAX=0;
    ll MAX2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    sort(a,a+n);int x=0;
    for(int i=1;i<n;i++){
        x+=a[n-1]-a[i];
    }
    ll ans=(a[n-1]-a[0])*(n-1)-x;

   // ll ans=(MAX-MIN-double((MAX-MAX2))/2)*2;
    cout<<ans<<" "<<a[0]+ans<<endl;
  }
}
