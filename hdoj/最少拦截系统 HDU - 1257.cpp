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
int main(){
  int n;
  while(cin>>n){
        int a[n+10];
        int dp[n+10];
    for(int i=1;i<=n;i++)
        cin>>a[i];
   int cnt=1;
   int i=2;
   dp[1]=a[1];
   while(i<=n){
      int minh=INF;int ans=-1;
   for(int j=1;j<=cnt;j++){
      if(a[i]<=dp[j]&&minh>dp[j]-a[i]){
          minh=dp[j]-a[i];
          ans=j;
      }
   }
     if(ans!=-1) dp[ans]=a[i];
     else{
        dp[++cnt]=a[i];
     }
      i++;
   }
    cout<<cnt<<endl;
  }

}
