/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/

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
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n,k;
   while(cin>>n>>k){
     if(n==1) {
            ll t=1;ll ans=0;
        while(t*2<=k){
            t*=2;
            ans++;
        }
        cout<<ans+1<<endl;
     }
     else{
        ll sum=0;
      ll i=1;ll ans=0;
      while(i<=k){
                ll t=n-sum/i;
                ans+=t;
                sum+=t*i;
                i=sum/n+1;
      }
      cout<<ans<<endl;
   }}
return 0;
}

