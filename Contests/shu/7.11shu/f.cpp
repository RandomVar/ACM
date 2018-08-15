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
/*ll c
void init(){

 for(int j=0;j<50;j++)
        c[0][j]=1;
  for(int i=1;i<50;i++)
    for(int j=0;j<50;j++)
  {
     if(i==j) c[i][j]=1;
     else if(j<i) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i][j-1])%mod;
     // cout<<j<<" "<<i<<" "<<c[i][j]<<endl;
  }

}*/
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    double n,p;
    while(cin>>n>>p){
   double ans=(n-p)*1.0/n;
    cout<<1-ans<<endl; 


    }


  }

