#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
int a[100010];

int main(){
  int n,d;
  while(cin>>n>>d){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n;i++){
       int p=upper_bound(a,a+n,a[i]+d)-a-1;
       if(p-i>=2)
          ans+=(ll)(p-i)*(p-i-1)/2;
    }
    cout<<ans<<endl;
  }

}
