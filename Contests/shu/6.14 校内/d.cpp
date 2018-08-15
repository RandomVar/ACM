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
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll f(ll n) {
    while(n >= 20180001) {
        n = f(n - 2018);
    }
    return n + 2017;
}
int main(){
 int t;
 cin>>t;
 while(t--){
    int n;
    cin>>n;
    if(n<20180001) cout<<f(n)<<endl;
    else cout<<20182017<<endl;

 }


}
