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
const double pi=3.1415926535897;
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  double m,n,r;
  while(cin>>m>>n>>r)
  {
    double ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    double xr=r*min(ay,by)/n;
    double xa=pi*fabs(ax-bx)/m;
    double xl=r*fabs(ay-by)/n;
    double ans1=xr*xa+xl;
    double ans2=(ay/n+by/n)*r;
    if(ans1>ans2) ans1=ans2;
    //double ans=min(ans1,ans2);
    printf("%.7lf\n",ans1);
  // cout<<ans1<<endl;
  }


  }

