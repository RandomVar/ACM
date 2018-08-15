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
  ll s;
  while(cin>>s)
{
     
    int flag=0;
     ll x=sqrt(s/2);
     if((2*x*x)==s) x--;
     for(int i=x;i>=1;i--)
     {
    
         if(s%i) continue;
         else{
             ll b=s/i;
             cout<<"Yes"<<endl;
             cout<<"0 0"<<endl;
             cout<<2*i<<" "<<"0"<<endl;
             cout<<i<<" "<<b<<endl;
           flag=1;
         }
     }
  if(!flag) cout<<"No"<<endl;
}

  }

