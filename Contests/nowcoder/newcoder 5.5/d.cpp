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
int a[3];
int main(){
  int n;
  while(cin>>n){
    a[1]=1;a[2]=2;
    int flag=1;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
      if(flag){
        if(t==a[1]) {
            for(int i=1;i<=3;i++)
                if(t!=i&&a[2]!=i) {a[2]=i;break;}
        }
        else if(t==a[2]){
            for(int i=1;i<=3;i++)
                if(t!=i&&a[1]!=i) {a[1]=i;break;}
        }
        else flag=0;
    }}
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

}
