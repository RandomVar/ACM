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
#include<map>
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
const int maxn=3*1e5+10;
map<ll,ll>cnt;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        cnt[t]++;
        }
        ll ans=0;
      map<ll,ll>::iterator it;
    for(it=cnt.end();it!=cnt.begin();it--){
        int flag=1;
        int x=0;
       ll xx=it->fir;
        x++;it->sec--;
        if(it->sec==0)
            cnt.erase(it);

      while(x<k){
         map <ll,ll> ::iterator p1;
         p1=cnt.upper_bound(xx/2);
         if(p1!=cnt.end()&&p1!=cnt.begin()){
            p1--;
           x++;
           p1->sec--;
           xx=p1->fir;
        if(p1->sec==0) cnt.erase(p1);
//        cout<<p1->fir<<endl;
//        ans.push_back(p1->fir);
        }
       else {flag=0;break;}
     }
     if(flag) ans++;
     else break;}
     cout<<ans<<endl;

    }
return 0;
  }

