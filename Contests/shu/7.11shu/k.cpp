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
const double eps = 1e-8;
int sgn(double x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }
struct Point {
    double x,y;
    Point(){};
    Point(double _x,double _y){x=_x;y=_y;}
    Point operator- (const Point &b){
     return Point(x-b.x,y-b.y);
    }
     Point operator+ (const Point &b){
     return Point(x+b.x,y+b.y);
    }
    double operator^ (const Point &b){
    return x*b.y-y*b.x;
    }
    double operator*(const Point &b){
    return x*b.x+y*b.y;
    }
    Point operator/(const double t){
    return Point(x/t,y/t);
    }
    Point operator*(const double t){
    return Point(x*t,y*t);
    }
 
};
double dissq(Point a,Point b){
return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double PointTOline( Point a,Point b,Point p){
    double ap_ab = (b.x - a.x)*(p.x - a.x)+(b.y - a.y)*(p.y - a.y);//cross( a , p , b );
    if ( ap_ab <= 0 )
        return sqrt( (p.x-a.x)*(p.x-a.x) + (p.y-a.y)*(p.y-a.y) );
 
    double d2 = ( b.x - a.x ) * ( b.x - a.x ) + ( b.y-a.y ) * ( b.y-a.y ) ;
    if ( ap_ab >= d2 ) return sqrt( (p.x - b.x )*( p.x - b.x ) + ( p.y - b.y )*( p.y - b.y ) ) ;
 
    double r = ap_ab / d2;
    double px = a.x + ( b.x - a.x ) *r;
    double py = a.y + ( b.y - a.y ) *r;
    return sqrt( (p.x - px)*(p.x - px) + (p.y - py)*(p.y - py) );
}

Point a[maxn],b[maxn];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n)
  {
      for(int i=1;i<=n;i++)
      {
          cin>>a[i].x>>a[i].y;
         // if(i==1) a[i].t=0;
          //else a[i].t=a[i-1].t+dissq(a[i],a[i-1]);
      }
      int m;
      cin>>m;
      for(int i=1;i<=m;i++)
      {
          cin>>b[i].x>>b[i].y;
        //if(i==1) b[i].t=0;
        //else b[i].t=b[i-1].t+dissq(b[i],b[i-1]);
      }

      double ans=1000000.0;
      Point pa=a[1];Point pb=b[1];
      int sa=1,sb=1;
      while(sa<n&&sb<m)
      {
          double lena=dissq(a[sa+1],pa);
          double lenb=dissq(b[sb+1],pb);
          double t=min(lena,lenb);
         Point va=(a[sa+1]-pa)/lena*t;
         Point vb=(b[sb+1]-pb)/lenb*t;
        ans=min(ans,PointTOline(pb,pb+vb-va,pa));
        //cout<<pb.x+vb.x-va.x<<endl;
        //cout<<ans<<endl;
         pa=pa+va;
         pb=pb+vb;
         if(sgn(lena-lenb)==0)
         {
            pa=a[++sa];
            pb=b[++sb];
         }
         else if(lena<lenb) pa=a[++sa];
         else pb=b[++sb];
      
      }
      printf("%.8f\n",ans);
      //cout<<ans<<endl;

  }


  }

