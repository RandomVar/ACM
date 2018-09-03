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

/*判断点c是否在线段ab上*/
bool onseg(Point a,Point b,Point c){
 if(sgn((b-a)^(c-a))==0&&
    sgn((c.x-a.x)*(c.x-b.x))<= 0 && sgn((c.y-a.y)*(c.y-b.y))<= 0)
        return 1;
 return 0;
}

struct Line{
 Point s,t;
 Line(){};
 Line(Point _s,Point _t){s=_s;t=_t;}
};

/*判断线段是否相交 51Nod - 1264 已验证*/
bool inter(Line l1,Line l2){
 if(sgn((l1.s-l2.s)^(l1.s-l1.t))*sgn((l1.s-l1.t)^(l1.s-l2.t))<0) return 0;
 if(sgn((l2.s-l1.s)^(l2.s-l2.t))*sgn((l2.s-l2.t)^(l2.s-l1.t))<0) return 0;
 if(min(l1.s.x,l1.t.x)<=max(l2.s.x,l2.t.x)&&min(l1.s.y,l1.t.y)<=max(l2.s.y,l2.t.y)
    &&min(l2.s.x,l2.t.x)<=max(l1.s.x,l1.t.x)&&min(l2.s.y,l2.t.y)<=max(l1.s.y,l1.t.y))
        return 1;
 return 0;
}

/*点在多边形内*/
/*射线法，poly[]的顶点数要大于等于3,点的编号0~n-1*/
/*返回值 -1:点在凸多边形外 0:点在凸多边形边界上 1:点在凸多边形内*/
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
 //cout<<"cnt "<<cnt<<endl;
  if(cnt%2) return 1;
 return -1;
}
Point p[110];

int main(){
 int n,m;int k=0;

 while(cin>>n){
    if(n==0) break;
    cin>>m;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>p[i].x>>p[i].y;
    }
    if(k) cout<<endl;
    cout<<"Problem "<<++k<<":"<<endl;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        Point e(x,y);
       if(inPoly(e,p,n)==-1) cout<<"Outside"<<endl;
       else cout<<"Within"<<endl;
    }
 }
return 0;
}
