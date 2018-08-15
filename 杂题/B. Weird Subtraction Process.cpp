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
void solve(ll a,ll b){
 if(a==0||b==0){
     cout<<a<<" "<<b<<endl;
     return ;

 }
 if(a>=2*b){
     a%=2*b;
     solve(a,b);
 }
 else if(b>=2*a){
    b%=a*2;
    solve(a,b);
 }
 else {
    cout<<a<<" "<<b<<endl;

 }

}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll a,b;
  while(cin>>a>>b){
    solve(a,b);


  }


}
