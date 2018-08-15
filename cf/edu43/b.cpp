#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
  ll n,m;
  while(cin>>n>>m){
    ll x,y;
    ll k;
    cin>>k;
    if(k<n){
        x=k+1;y=1;
    }
    else{
        k-=n;
        ll a=(m-1)*2;
        y=k%a;
        if(y>(m-2)) y=m-(y-(m-2))+1;
        else y=y+2;
        x=n-k/(m-1);
    }
    cout<<x<<" "<<y<<endl;
  }

}
