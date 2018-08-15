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
const double eps=1e-7;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
double l;int n;
double rv[30],kv[30];
double judge(double r){
 double mi=r/rv[n]+(l-r)/kv[n];
 double ans=1e100;
 for(int i=1;i<n;i++)
 {
     double tmp=r/rv[i]+(l-r)/kv[i];
     ans=min(ans,tmp-mi);
 }
 return ans;
}
int main(){
 // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //double l;int n;
  while(scanf("%lf%d",&l,&n)==2){
    for(int i=1;i<=n;i++)
      scanf("%lf%lf",&rv[i],&kv[i]);
   double low=0,high=l;

   while(high-low>eps){
    double m1=low+(high-low)/3;
    double m2=high-(high-low)/3;
    if(judge(m1)>judge(m2))
        high=m2;
    else low=m1;
   }
    double ans=judge(low);
    if(ans<0.0)
            printf("The cheater cannot win.\n");
    else
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", ans*3600, low, l-low);
  }

}
