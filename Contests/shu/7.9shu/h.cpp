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
int a[2100];
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;cin>>t;
  while(t--){
        int n;
      cin>>n;
  int ans=0;
    for(int i=1;i<=2*n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]+a[2*n-i+1]);

    }
cout<<ans<<endl;


  }
return 0;

  }

