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
ll dp[550][550];
ll a[550][550];
int z[550][550];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int  r,c,x,y,zn;
  while(cin>>r>>c>>x>>y>>zn){

     for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
           cin>>a[i][j];
     mem(dp,0);
     mem(z,0);
     for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
               dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
               z[i][j]=z[i-1][j]+z[i][j-1]-z[i-1][j-1]+(a[i][j]==0?1:0);
     }
  
 ll ans = 0;
 deque<int> dq;
 for(int i=1;i<=r;i++)
   for(int j=i;j<=r&&j-i<x;j++){
     dq.clear();
     dq.push_back(0);
     for(int k=1;k<=c;k++){
       //int f=dq.front();
        while(!dq.empty()&&((k-dq.front())>y||(z[j][k]-z[i-1][k])-(z[j][dq.front()]-z[i-1][dq.front()])>zn))
            dq.pop_front();
         ll x=dp[j][k]-dp[i-1][k];
         if(!dq.empty())
            ans=max(ans,x-(dp[j][dq.front()]-dp[i-1][dq.front()]));
          while(!dq.empty()&&x<=dp[j][dq.back()]-dp[i-1][dq.back()])
             dq.pop_back();
          dq.push_back(k);
     }

   }
    cout<<ans<<endl;
   
  }

return 0;
  }

/*

5 5 3 3 4
0 0 10 0 0
3 4 0 2 3
-1 3 0 -8 3
0 0 32 -9 3
3 0 45 3 0

5 5 2 3 2
0 4 34 4 6
0 5 4 6 3
5 0 4 5 4
100 0 4 3 2
0 0 0 0 0

2 2 2 2 2
-1 -1
-1 -1
*/
