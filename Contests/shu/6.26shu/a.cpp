#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
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
  ll s,k;
  while(cin>>s>>k){

    if(s%k||s<2*k) cout<<-1<<endl;
    else {
        ll x=s/k;
        cout<<k<<" "<<(x-1)*k<<endl;


    }



  }


}
