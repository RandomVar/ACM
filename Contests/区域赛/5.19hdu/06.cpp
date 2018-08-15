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
const double eps = 1e-8;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll gcd(ll a,ll b){
         if(a < b){
                   long long temp;
                   temp = a;
                   a = b;
                   b = temp;
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}
struct node{
  ll fz;
  ll fm;
  int id;
  bool operator<(const node &b)const{
      if( fz*b.fm==b.fz*fm) return id>b.id;
      return fz*b.fm<b.fz*fm;
  }

}a[1010];
int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1){
    for(int i=1;i<=n;i++){
        ll x,b,c;
        scanf("%lld%lld%lld",&x,&b,&c);
        //cin>>x>>b>>c;
        ll t=gcd(c,x+b);
        a[i].fz=(c)/t;
        a[i].fm=(x+b)/t;
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>1;i--){
    printf("%d ",a[i].id);
    // cout<<a[i].id<<" ";
    }
    printf("%d\n",a[1].id);
    //cout<<a[1].id<<endl;
   }

}
