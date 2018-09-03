#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }

/****Point 定义*****/
struct Point {
    double x,y;
    Point(){};
    Point(double _x,double _y){x=_x;y=_y;}
    Point operator- (const Point &b){
     return Point(x-b.x,y-b.y);
    }

    double operator^ (const Point &b){
    return x*b.y-y*b.x;
    }
    double operator*(const Point &b){
    return x*b.x+y*b.y;
    }
    };

/*判断点c是否在线段ab上 已验证*/
bool onseg(Point a,Point b,Point c){
 if(sgn((b-a)^(c-a))==0&&
    sgn((c.x-a.x)*(c.x-b.x))<= 0 && sgn((c.y-a.y)*(c.y-b.y))<= 0)
        return 1;
 return 0;
}

/****Line 定义****/
struct Line{
 Point s,t;
 Line(){};
 Line(Point _s,Point _t){s=_s;t=_t;}
};

int panduan(Line seg,Line a){
  if(sgn((a.s-seg.s)^(a.s-seg.t))<0&&sgn((a.s-a.t)^(a.s-seg.t))>0) return 0;//直线在逆时针方向
  if(sgn((a.s-seg.s)^(a.s-seg.t))>0&&sgn((a.s-a.t)^(a.s-seg.t))<0) return -1;
  return 1;
}
Line l[110];
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        Point a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        l[i].s=a;l[i].t=b;
    }
    Point tl,tr;
    if(sgn(l[0].s^l[0].t)<0) {
         tl=l[0].t;
         tr=l[0].s;
    }
    else {
        tl=l[0].s;
         tr=l[0].t;
    }
     Point a(0,0);
     Line xx(a,tl);
     int flag=1;
    // cout<<"flag"<<endl;
    while(flag){
             // cout<<"flag"<<endl;
        int i;
     for(i=1;i<n;i++){
        int re=panduan(l[i],xx);
    cout<<re<<endl;
      if(re==0){
        if(panduan(l[i],Line(xx.s,tl))==0) {flag=0;break;}
        tr=xx.t;
        xx.t.x+=tl.x;
        xx.t.y+=tl.y;
        xx.t.x/=2;xx.t.y/=2;
      }
      else if(re==-1) {
         if(panduan(l[i],Line(xx.s,tr))==-1) {flag=0;break;}
        tl=xx.t;
        xx.t.x+=tr.x;
        xx.t.y+=tr.y;
        xx.t.x/=2;xx.t.y/=2;
      }
     // else continue;
     }
     if(i==n-1&&flag) break;
    }
    if(flag) cout<<"Yes!"<<endl;
    else cout<<"No!"<<endl;

}
}
