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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll a[20];
int main(){
    ll zong=0;int nhas=0;
  for(int i=0;i<14;i++){
    cin>>a[i];
    if(a[i]) nhas++;
    zong+=a[i];
  }
  ll shuchu=0;
  for(int i=0;i<14;i++){
        ll ans=0;
    if(a[i]){
       int x=a[i]/14;
       int t=a[i]%14;
       if(x%2==1){
          ans=(nhas-1)*x+zong-a[i];
          for(int j=1;j<=t;j++){
            if(a[(i+j)%14]) ans-=a[(i+j)%14]+x;
            else ans+=x+1;
       }}
       else{
        ans=(14-nhas+1)*x;
        for(int j=1;j<=t;j++){
            if(a[(i+j)%14]) ans+=a[(i+j)%14]+x+1;
            else ans-=x;
       }}
       shuchu=max(shuchu,ans);
    }
  }
  cout<<shuchu<<endl;
}
/*
18 1 0 0 0  0 0 0 0 0 0 0 0 0 0
**/
