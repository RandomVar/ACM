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
const int maxn=2*1e5+1000;
ll c[maxn];
ll sum[maxn];
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(scanf("%d",&n)==1){
     for(int i=0;i<=n;i++)
        scanf("%lld",&c[i]);
        //cin>>c[i];
     memset(sum,0,sizeof(sum));
     ll ans=0;
     for(int i=n;i>=0;i--){
//        m[i]=min(m[i+1],c[i]);
        sum[i]=sum[i+1]+c[i];
        if(sum[i]>=i) {ans=i;break;}
     }
     printf("%lld\n",ans);
   //cout<<ans<<endl;
  }


}
