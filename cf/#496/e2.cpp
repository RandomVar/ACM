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
const int maxn=2*1e5+100;
int a[maxn],cnt[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m){

   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      if(a[i]>m){
            dp[i][1]+=dp[i-1][0]+dp[i-1][2];
            dp[i][0]+dp[i-1][1]+dp[i-1][3];
      }


   }
  

  }


  }

