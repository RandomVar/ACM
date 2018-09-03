#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const double eps = 1e-8;



int sgn(double x) {/*ÅÐ¶ÏxµÄÕý¸ºÐÔ*/
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
bool online(Point a,Point b,Point c){
 if(fabs((b-a)*(c-a))>eps) return 0;
 if(c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y)&&
    c.x>=min(a.x,b.x)&&c.x<=max(a.y,b.y))
        return 1;
 return 0;
}

struct Line{
 Point a,b;
 Line(){};
 Line(Point _a,Point _b){a=_a;b=_b;}
};

bool inter(Line l1,Line l2){
 if(sgn((l1.a-l2.a)^(l1.a-l1.b))*sgn((l1.a-l1.b)^(l1.a-l2.b))<0) return 0;
 if(sgn((l2.a-l1.a)^(l2.a-l2.b))*sgn((l2.a-l2.b)^(l2.a-l1.b))<0) return 0;
 if(min(l1.a.x,l1.b.x)<=max(l2.a.x,l2.b.x)&&min(l1.a.y,l1.b.y)<=max(l2.a.y,l2.b.y)
    &&min(l2.a.x,l2.b.x)<=max(l1.a.x,l1.b.x)&&min(l2.a.y,l2.b.y)<=max(l1.a.y,l1.b.y))
        return 1;
 return 0;
}

double calarea(Point p[],int n){
 double res=0;
 for(int i=0;i<n;i++){
    res+=(p[i]^p[(i+1)%n])/2;
 }
 return fabs(res);
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    Point p1(x1,y1);
    Point p2(x2,y2);
    Point p3(x3,y3);
    Point p4(x4,y4);
    Line l1(p1,p2);
    Line l2(p3,p4);
    if(inter(l1,l2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
  }


