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
const int maxn=1e5+100;
int a[maxn];
int main(){

  int t;
  cin>>t;
  while(t--){
      int n;
        cin>>n;
      for(int i=0;i<n;i++){
          cin>>a[i];
      }
      sort (a,a+n);
      ll ans=(ll)a[0]*(n-1);
      for(int i=1;i<n;i++)
        ans+=a[i];
      cout<<ans<<endl;

  }
}
