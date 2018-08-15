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
    ll zong=0;int shu=0;
  for(int i=0;i<14;i++){
    cin>>a[i];
    zong+=a[i];
    if(a[i]) shu+=1;
  }
  ll shuchu=0;
  for(int i=0;i<14;i++){
    if(a[i]){
        ll ans=0,cnt=0;
      int t=a[i]%14;
      int jishu=0;
        for(int j=1;j<=t;j++){
            if(a[(i+j)%14]) cnt+=a[(i+j)%14]+1;
            else jishu++;
        }
       int x=a[i]/14;
       if(x%2==1) ans=zong-a[i]+shu-1-cnt+jishu*(x+1);
       else ans=(14-shu+1-t+jishu)*x+cnt;
       shuchu=max(ans,shuchu);
    }
  }
  cout<<shuchu<<endl;
}
/*
13 1 0 0 0  0 0 0 0 0 0 0 0 0 0
**/
