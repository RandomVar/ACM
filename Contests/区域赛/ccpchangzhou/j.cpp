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
const ll INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll cnt1[100010];
ll cnt2[100010];
const ll mod=998244353;
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll t;
   scanf("%lld",&t);
//   cin>>t;
   while(t--){
     ll n,m;
     scanf("%lld%lld",&n,&m);
//     cin>>n>>m;
     mem(cnt1);
     mem(cnt2);
     for(ll i=0;i<m;i++){
        ll l,r,x;
        scanf("%lld%lld%lld",&l,&r,&x);
//        cin>>l>>r>>x;
        r++;
        if(x==2){
        cnt1[l]++;
        cnt1[r]--;
     }
     else {
       cnt2[l]++;
       cnt2[r]--;
     }
     }
     ll a1=cnt1[1];
     ll a2=cnt2[1];
     ll cu1=a1;
     ll cu2=a2;
     for(ll i=2;i<=n;i++){
        cu1+=cnt1[i];
        cu2+=cnt2[i];
      //  cout<<cu1<<" "<<cu2<<endl;
        a1=min(cu1,a1);
        a2=min(cu2,a2);
     }
     ll ans=(quickmod(2,a1)*quickmod(3,a2))%mod;
     printf("%lld\n",ans);
//     cout<<ans<<endl;
     }
   }

