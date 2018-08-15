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
  ll a,b,c;
  while(cin>>a>>b>>c)
  {
      ll cnt=-INF;
      for(int i=0;i<(1<<2);i++)
      {
          ll ans=0;
          if(i&(1<<0)) ans=a*b;
          else ans=a+b;
          if(i&(1<<1)) ans=ans*c;
          else ans=ans+c;
          cnt=max(ans,cnt);

      }
 for(int i=0;i<(1<<2);i++)
      {
          ll ans=0;
          if(i&(1<<0)) ans=c*b;
          else ans=c+b;
          if(i&(1<<1)) ans=ans*a;
          else ans=ans+a;
          cnt=max(ans,cnt);

      }

      cout<<cnt<<endl;
  }


  }

