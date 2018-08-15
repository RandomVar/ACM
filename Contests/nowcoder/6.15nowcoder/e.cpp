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
int cnt[5];
int main(){
  int n;
  while(cin>>n){
        memset(cnt,0,sizeof(cnt));
        int flag=1;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(t==25) cnt[1]++;
        else if(t==50){
            if(cnt[1]==0) flag=0;
            cnt[1]--;
            cnt[2]++;

        }
       else if(t==100){
          if(cnt[1]>=1&&cnt[2]>=1){
            cnt[1]--;cnt[2]--;
          }
          else if(cnt[1]>=3){
            cnt[1]-=3;
          }
          else flag=0;
       }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

}
