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
string s[1010];
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<n;i++)
        cin>>s[i];
    int flag=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<4;j++)
          if(!flag&&s[i][j]=='O'&&s[i][j+1]=='O') {
             flag=1;s[i][j]='+';s[i][j+1]='+';break;}
    if(flag){
        cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
    }
    else cout<<"NO"<<endl;
  }
  return 0;
}

