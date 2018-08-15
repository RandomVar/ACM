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
int a[110];
int sum[110];
vector<int>vec;
int main(){
  int n;
  while(cin>>n){
        vec.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) vec.pb(i);
    }
    sum[n+1]=0;sum[0]=0;
    for(int i=n;i>=0;i--){
        sum[i]=sum[i+1]+a[i];
    }
    int pre=0;int cnt=0;int ans=0;
   for(int i=0;i<vec.size();i++){
      if(vec[i]-pre>1) {
        ans=max(ans,cnt+sum[pre]);
      }
      cnt++;
      pre=vec[i];
   }
    cnt+=n-pre;
    ans=max(ans,cnt);
    cout<<ans<<endl;
  }


}
