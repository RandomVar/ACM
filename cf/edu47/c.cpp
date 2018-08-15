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
  int n,m;
  while(cin>>n>>m)
  {
      ll ans=0;
      for(int i=1;i<=m;i++)
      {
          ll x,d;
          cin>>x>>d;
          if(d>=0) 
          { 
              ans+=n*x+d*(n-1)*n/2;
          } 
          else{
            if(n%2){
              int t=(n+1)/2;
              ans+=n*x+2*d*t*(t-1)/2;
            }
            else{
                int t=n/2;
                ans+=n*x+2*d*t*(t-1)/2+(n-t)*d;
            }
          }
      }
      double daan=(double)ans/(1.0*n);
      printf("%.7lf\n",daan);
      //cout<<daan<<endl;
  }


  }

/*
5 3
-1 -3
-4 -6
-3 -10
*/