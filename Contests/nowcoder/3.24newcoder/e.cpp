#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;

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
double cal(Point a,Point b){
return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
double cnt[1100];
Point p[1100];
int main(){
  int t;
  cin>>t;
  while(t--){
   int n;cin>>n;int ans=0;
   for(int i=0;i<n;i++)
   {

       cin>>p[i].x>>p[i].y;

   }

   for(int i=0;i<n;i++){
        int k=0;int num=0;
     for(int j=0;j<n;j++){
        cnt[k++]=cal(p[i],p[j]);

     }
     sort(cnt,cnt+k);
     for(int j=1;j<k;j++){
        if(cnt[j]&&cnt[j]==cnt[j-1]) num++;
        else if(num) {ans+=num*(num+1);num=0;}
     }
     ans+=num*(num+1);num=0;
   }
   if(ans) cout<<ans<<endl;
   else cout<<"WA"<<endl;
}
}
