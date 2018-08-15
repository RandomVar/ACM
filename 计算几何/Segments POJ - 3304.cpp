#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const double INF=0x3f3f3f3f;
const double eps=1e-8;

struct point{
  double x,y;
  point operator-(point a){
  return point{x-a.x,y-a.y};
  }
};
struct line{
  point a,b;
}lines[110];

double multi(point p1,point p2,point p0){
 return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double cross(point a,point b){
return a.x*b.y-a.y*b.x;
}
bool online(line a,line b){
 if(max(a.b.x,a.a.x)>=min(b.b.x,b.a.x)&&max(b.b.x,b.a.x)>=min(a.b.x,a.a.x)&&
    max(a.a.y,a.b.y)>=min(b.a.y,b.b.y)&&
    multi(b.a,a.b,a.a)*multi(a.b,b.b,a.a)>0&&multi(a.a,b.b,b.a)*multi(b.b,a.b,b.a)>0)
    //multi(a.a,b.b,b.a)*multi(a.b,b.b,b.a)<=0&&multi(b.a,a.b,a.a)*multi(b.b,a.b,a.a)>=0)
    return 1;
 return 0;
 }

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;cin>>n;
    for(int i=0;i<n;i++){
       cin>>lines[i].a.x>>lines[i].a.y>>lines[i].b.x>>lines[i].b.y;
    }
    point r1,l1;
    point r,l;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if(!online(lines[i],lines[j])){
            line a=lines[i];line b=lines[j];
          //  double x=cross(a.a,b.a);
        //    double y=cross(a.a,b.b);
            double x=multi(b.a,b.b,a.a);
            if(x>0) {
               // l=a.b-a.a;
                //r=b.b-b.a;
                l=b.a-a.a;
                r=b.b-a.a;
            }
            else {
               r=b.a-a.a;
               l=b.b-a.a;
            }
          double  y=cross(l,l1);
            if(y>0) l1=l;
           double z=cross(r,r1);
            if(z<0) r1=r;
            x=multi(b.a,b.b,a.b);
            if(x>0) {
               // l=a.b-a.a;
                //r=b.b-b.a;
                l=b.a-a.b;
                r=b.b-a.b;
            }
            else {
               r=b.a-a.b;
               l=b.b-a.b;
            }
            y=cross(l,l1);
            if(y>0) l1=l;
            z=cross(r,r1);
            if(z<0) r1=r;
           }
        }
    }
    if(cross(l1,r1)>=0) cout<<"Yes!"<<endl;
    else cout<<"No!"<<endl;
  }
  return 0;
}
