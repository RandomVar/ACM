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
const int maxn=2*1e5+1000;
ll a[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n)
  {
      for(int i=1;i<=n;i++)
       cin>>a[i];
       int i=0;int j=n+1;
       ll s1=0;ll s2=0;
       ll ans=0;
       while(i<=n&&j>0&&i<j)
       {
          if(s1==s2) {
            
              ans=s1;
              if(i+1==j-1) break;
              s1+=a[++i];s2+=a[--j];
              }
        else if(s1>s2)
        {
            s2+=a[--j];
        }
        else if(s1<s2)
        {
            s1+=a[++i];
        }
       }
     cout<<ans<<endl;

  }


 return 0;
  }

