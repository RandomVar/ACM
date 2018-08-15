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
const double eps = 1e-7;
int sgn(double x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }
int n;double m;
double a[2100];
int check(double mid)
{

    for(int i=1;i<=2*n;i++)
    {
        double t=(mid+m)/a[i];
        mid-=t;
        if(mid<0) return 0;
    }
    return 1;
}

int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   while(scanf("%d%lf",&n,&m)==2)
   {
       for(int i=1;i<2*n;i+=2)
        scanf("%lf",&a[i]);   
        
        scanf("%lf",&a[2*n]);
     
        for(int i=2;i<2*n;i+=2)
        scanf("%lf",&a[i]);
      double l=0;double r=2e9;
       double ans=0;
    
       double mid;
        for(int i = 0; i < 100; ++i) {
           mid = (l + r) / 2.0;
           if(check(mid) ) r = mid;
           else l = mid;
        }
        
        if(l>1e9) printf("-1\n");
        else printf("%.7lf\n",l);
        }

 return 0;
  }

