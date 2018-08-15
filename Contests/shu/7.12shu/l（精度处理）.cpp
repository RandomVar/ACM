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
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
    map<string,double>dp;
    dp["pink"]=0.0;
    for(int i=1;i<=n;i++)
    {
         string s1,s2;
         cin>>s1>>s2;
         double x;
         cin>>x;
         x=log(x);
         if(!dp.count(s1))
           dp[s1]=dp[s2]+x;
          if(!dp.count(s2))
           continue;
        else if(dp[s1]<dp[s2]+x)
             dp[s1]=dp[s2]+x;
         //if(dp[s1]>10) dp[s1]=10;
    }
    if(dp["blue"]>4.0) cout<<10.0<<endl;
    else if(dp["blue"]==0)  cout<<0.0<<endl;
    else 
     printf("%.7lf\n",min(10.0,pow(exp(1),dp["blue"])));
    //cout<<min(10.0,pow(exp(1),dp["blue"]))<<endl;
    //printf("%.9f\n",);
   // cout<<dp["blue"]<<endl;
  }


  }

