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

double calarea(Point p[],int n){
 double res=0;
 for(int i=0;i<n;i++){
    res+=(p[i]^p[(i+1)%n])/2;
 }
 //cout<<res<<endl;
 return fabs(res);
}

int gcd ( int a,int b){
    if(a<b) swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}

/*多边形边上整点数*/
int onedge(Point p[],int n){
 int ans=0;
 for(int i=0;i<n;i++){
    ans+=gcd(fabs(int(p[(i+1)%n].x-p[i].x)),fabs(int(p[(i+1)%n].y-p[i].y)));
 }
 //cout<<ans<<endl;
 return ans;
}


int main(){
 int n;int k=0;
 while(cin>>n){
     k++;
    Point p[n];
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        p[i].x=x;p[i].y=y;
    }
    cout<<"Case "<<k<<":"<<onedge(p,n)<<endl;
    //printf("Case %d:%d\n",k,onedge(p,n));
 }
 return 0;
}
