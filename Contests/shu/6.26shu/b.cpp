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
typedef unsigned long long ll;
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);

/****Point 定义*****/
struct Point {
    ll x,y;
    Point(){};
    Point(ll _x,ll _y){x=_x;y=_y;}
    Point operator- (const Point &b){
     return Point(x-b.x,y-b.y);
    }

    ll operator^ (const Point &b){
    return x*b.y-y*b.x;
    }
    ll operator*(const Point &b){
    return x*b.x+y*b.y;
    }
    };
Point p[200010];
ll multiply(Point sp, Point ep, Point op) //三角形三个点的坐标
{
    return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}
ll calarea(int n){
 ll ans=INF;
 for(int i=0;i<n;i++){
     ll x=multiply(p[i],p[(i+1)%n],p[(i+2)%n]);
        ans=min(ans,x>0?x:-x);
 }
 return ans;
}

int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
     for(int i=0;i<n;i++)
         cin>>p[i].x>>p[i].y;
     cout<<calarea(n)<<endl;



  }
}
