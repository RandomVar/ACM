#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1.0);
int sgn(double x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }
int main(){
  int t;
  cin>>t;
  while(t--){
    double a,b,x,y;
    cin>>x>>a>>y>>b;
    if(sgn(a*log(x)-b*log(y))==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


   // else if(sgn((double)a/(1.0*b)-(double)log(1.0*y)/log(1.0*x))==0) cout<<"Yes"<<endl;
    //else cout<<"No"<<endl;
  }
}
