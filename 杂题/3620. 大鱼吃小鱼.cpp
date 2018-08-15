/*
先吃a[i]>0的，再吃a[i]<0的
对于a[i]>0的先吃体积大的
对于a[i]<0的先吃吃了它之后体积大的（a+w大的）

再二分check答案
*/
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
const int maxn=1e6+100;
struct node{
   ll w,a;
   bool operator <(const node &b)const{
       if(a>=0&&b.a<0)
         return 1;
       if(b.a>=0&&a<0)
        return 0;
      if(a>=0&&b.a>=0)
        return w<b.w;
     return a+w>b.a+b.w;
  
   }

}a[maxn];
int check(ll mid,int n){
    ll ans=mid;
    for(int i=1;i<=n;i++)
       if(ans<a[i].w) return 0;
       else ans+=a[i].a;
    if(ans<=0) return 0;
    return 1;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       for(int i=1;i<=n;i++)
         cin>>a[i].w>>a[i].a;
      sort(a+1,a+1+n);
      ll l=0;ll r=1e16;
      while(r-l>1)
      {
          ll mid=(l+r)/2;
          if(check(mid,n)==0)
            l=mid;            
        else r=mid;
      }

      cout<<r<<endl;
   
   }

 return 0;
  }

