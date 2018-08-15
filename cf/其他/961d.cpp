#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const double eps = 1e-8;
const double PI = acos(-1.0);
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

    double operator^ (const Point &b){
    return x*b.y-y*b.x;
    }
    double operator*(const Point &b){
    return x*b.x+y*b.y;
    }
    }p[maxn];
struct Line{
 Point s,t;
 Line(){};
 Line(Point _s,Point _t){s=_s;t=_t;}
};
bool online(Point a,Line l){
 if(sgn((l.s-a)^(l.t-a))==0)
        return 1;
 return 0;
}
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>p[i].x>>p[i].y;
   }
   if(n<=4) cout<<"YES"<<endl;
   else{
    Line l1,l2;
    l1.s=p[0];
    int flag=1;
        l1.t=p[1];
        int i=2;
        while(online(p[i],l1))
            i++;
        l2.s=p[i++];
        while(online(p[i],l1))
            i++;
        l2.t=p[i];
      for(i;i<n;i++){
        if(!online(p[i],l1)&&!online(p[i],l2)) {flag=0;break;}
      }
    if(!flag){
      flag=1;
      l2.s=p[1];
      l1.t=p[2];
      int i=3;
      while(online(p[i],l1))
        i++;
      l2.t=p[i];
      for(i;i<n;i++)
        if(!online(p[i],l1)&&!online(p[i],l2)) {flag=0;break;}
    }
    if(!flag){
        flag=1;
        l2.s=p[1];
        l2.t=p[2];
        int i=3;
        while(online(p[i],l2))
        i++;
        l1.t=p[i];
        for(i;i<n;i++)
        if(!online(p[i],l1)&&!online(p[i],l2)) {flag=0;break;}
    }
    if(flag==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
  return 0;

}
