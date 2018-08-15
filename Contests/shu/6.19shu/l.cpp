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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e6+100;
vector<int>d[maxn];
int vis[maxn];
void init(){
    memset(vis,0,sizeof(vis));
   for(int i=2;i<maxn;i++){
      if(!vis[i]){
        for(int j=i;j<maxn;j+=i)
        {
            d[j].push_back(i);
            vis[j]=1;

        }
      }
   }
}
ll cal(ll x,int p){
    int m=d[p].size();
    ll num=0;
    for(int i=1;i<(1<<m);i++){
         ll ans=1;int ant=0;
         for(int j=0;j<m;j++){
            if(i&(1<<j)){
                ans*=d[p][j];
                ant++;
            }
         }
            if((ant-1)%2) num-=(x/ans);
           else num+=(x/ans);

     }
  return x-num;
}

int main(){
   int t;
   init();
   scanf("%d",&t)==1;

   while(t--){
      ll x,p,k;
      scanf("%lld%lld%lld",&x,&p,&k);
      ll ans1=cal(x,p);
      //cout<<ans1<<endl;
      //cout<<cal(12,p)<<endl;
      ll low=x+k-1;ll high=1e8;
       ll ans=-1;
  while(high-low>1){
    int mid=(high+low)/2;
    ll ans2=cal(mid,p)-ans1;
    //cout<<mid<<" "<<ans2<<endl;
    if(ans2>=k) high=mid;
    else low=mid;
  }
    printf("%lld\n",high);

   }
}
