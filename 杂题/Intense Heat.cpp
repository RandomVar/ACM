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

const int maxn=1e5+100;
double a[maxn],b[maxn],c[maxn];
const double eps = 1e-7;
const double PI = acos(-1.0);
int sgn(double x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }
    int n,k;
int check(){
 double ans=0;
  double mm=0;
  for(int i=1;i<=n;i++){
     ans+=b[i];
     c[i]=ans;
    if(i>=k&&ans>=mm)
        return 1;
    if(i>=k)
      if(mm>c[i-k+1])  {
        mm=c[i-k+1];
       }
      //mm=min(mm,b[i-k+1]);
    }
return 0;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    //int n,k;
    cin>>n>>k;double low=0;double high=5000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
      // low=min(low,a[i]);
      // high=max(high,a[i]);
    }
   // cout<<low<<" "<<high<<endl;
    while(sgn(high-low)>=0){
           // cout<<high<<" "<<low<<endl;
        double mid=(high+low)/2.0;
        for(int i=1;i<=n;i++)
            b[i]=a[i]-mid;
        if(check())
            low=mid+eps;
        else high=mid-eps;
        //cout<<1<<endl;
    }
    printf("%.7lf\n",low);
    //cout<<low<<endl;



  }


  }

