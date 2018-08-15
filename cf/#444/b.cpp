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

int a[5][10];
int cnt[5][15];

int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while(cin>>n){
      //  ans=0;
        mem(cnt,0);
    for(int j=0;j<n;j++)
      for(int i=1;i<=6;i++)
        cin>>a[j][i];
        for(int j=0;j<n;j++)
          for(int i=1;i<=6;i++){
         cnt[j][a[j][i]]++;
      }
      int flag=0;
      for(int i=1;i<=9;i++)
      if(!cnt[0][i]&&!cnt[1][i]&&!cnt[2][i]) {flag=1;cout<<i-1<<endl;break;}
     if(flag) continue;
     int ans=-1;
     for(int i=10;i<100;i++){
        int x=i/10;int y=i%10;
        int flag=0;
        for(int j=0;j<n;j++){
          for(int k=0;k<n;k++){
             if(j!=k){
                if(cnt[j][x]&&cnt[k][y])
                    {
                        flag=1;break;
                    }
             }
        }
        if(flag) break;
        }
        if(!flag)  {ans=x*10+y-1;break;}
     }
     if(ans!=-1) {cout<<ans<<endl;continue;}
     for(int i=100;i<=999;i++){
        int x=i/100;int y=i/10%10;int z=i%10;
        int flag=0;
        for(int j=0;j<n;j++){
          for(int k=0;k<n;k++){
            for(int e=0;e<n;e++){
                if(j!=k&&k!=e&&e!=j){
                    if(cnt[j][x]&&cnt[k][y]&&cnt[e][z])
                    {
                        flag=1;
                    }
            }
            }}}
            if(!flag)  {ans=x*100+y*10+z-1;break;}
     }

     cout<<ans<<endl;

  }

  }

