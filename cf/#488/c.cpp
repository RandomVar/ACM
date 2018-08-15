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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
    };

struct Line{
 Point s,t;
 Line(){};
 Line(Point _s,Point _t){s=_s;t=_t;}
};
bool onseg(Point a,Point b,Point c){
 if(sgn((b-a)^(c-a))==0&&
    sgn((c.x-a.x)*(c.x-b.x))<= 0 && sgn((c.y-a.y)*(c.y-b.y))<= 0)
        return 1;
 return 0;
}
bool inter(Line l1,Line l2){
 if(sgn((l1.s-l2.s)^(l1.s-l1.t))*sgn((l1.s-l1.t)^(l1.s-l2.t))<0) return 0;
 if(sgn((l2.s-l1.s)^(l2.s-l2.t))*sgn((l2.s-l2.t)^(l2.s-l1.t))<0) return 0;
 if(min(l1.s.x,l1.t.x)<=max(l2.s.x,l2.t.x)&&min(l1.s.y,l1.t.y)<=max(l2.s.y,l2.t.y)
    &&min(l2.s.x,l2.t.x)<=max(l1.s.x,l1.t.x)&&min(l2.s.y,l2.t.y)<=max(l1.s.y,l1.t.y))
        return 1;
 return 0;
}
int inPoly(Point p,Point poly[],int n){
 Point p1(-INF+100,p.y);
 Line ray(p,p1);
 Line side;
 int cnt=0;
 for(int i=0;i<n;i++){
    side.s=poly[i];
    side.t=poly[(i+1)%n];
    if(onseg(side.s,side.t,p)) return 0;
    if(sgn(side.s.y-side.t.y)==0) continue;//平行轴不考虑

    if(onseg(ray.s,ray.t,side.s)){
       if(sgn(side.s.y-side.t.y)>0) cnt++;}
   else if(onseg(ray.s,ray.t,side.t)){
      if(sgn(side.t.y-side.s.y)>0) cnt++;}
    else if(inter(side,ray)) cnt++;
 }
  if(cnt%2) return 1;
 return -1;
}
Point p1[4];
Point p2[4];
int main(){
  for(int i=0;i<4;i++)
    cin>>p1[i].x>>p1[i].y;
   for(int i=0;i<4;i++)
        cin>>p2[i].x>>p2[i].y;
        int flag=0;
   for(int i=0;i<4;i++){
      if(inPoly(p1[i],p2,4)!=-1){flag=1;break;}
      if(inPoly(p2[i],p1,4)!=-1){flag=1;break;}

   }
   Point px;
   if(p1[0].x!=p1[3].x){
        px.x=(p1[0].x+p1[3].x)/2;
        px.y=(p1[2].y+p1[1].y)/2;
   }
   else{
       px.x=(p1[1].x+p1[2].x)/2;
        px.y=(p1[0].y+p1[3].y)/2;
   }
   Point py;
   if(p2[0].x!=p2[3].x){
        py.x=(p2[0].x+p2[3].x)/2;
        py.y=(p2[2].y+p2[1].y)/2;
   }
   else{
       py.x=(p2[1].x+p2[2].x)/2;
        py.y=(p2[0].y+p2[3].y)/2;
   }
   if(inPoly(px,p2,4)!=-1) flag=1;
   if(inPoly(py,p1,4)!=-1) flag=1;
   if(flag) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
return 0;
}
