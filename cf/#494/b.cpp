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
     int a,b,n;
  while(cin>>a>>b>>n)
  {
    if(a == n/2)
    {
      cout<<1;
      b--;
    }
    for(int i = 1;i<=n-1;i++)
    {
      if(i%2)
      {
        cout<<0;
        a--;
      }
      else
      {
        cout<<1;
        b--;
      }
    }
    if(n%2 == 0)
    {
      for(int i = 1;i<=b;i++)
         cout<<1;
      for(int i = 1;i<=a;i++)
        cout<<0;
    }
    else
    {
      for(int i = 1;i<=a;i++)
        cout<<0;
      for(int i = 1;i<=b;i++)
        cout<<1;
    }
    cout<<endl;
  }


}
