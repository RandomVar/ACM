#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1010;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);

const double eps = 1e-8;
const double PI = 3.1415926;
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


double dissq(Point a,Point b){
return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
/*求凸包，Graham算法*/
/*返回凸包结果st[0~top-1]为凸包边上的点编号 top为凸包边上的点的总数*/
Point lis[maxn];
int st[maxn],top;
bool cmp(Point a,Point b){
    int flag=sgn((a-lis[0])^(b-lis[0]));
 if(flag>0) return 1;
 if(flag==0&&sgn(dissq(a,lis[0])-dissq(b,lis[0]))<=0) return 1;
 return 0;
}

void graham(int n){
  Point p0;
  p0=lis[0];int k=0;
  for(int i=1;i<n;i++){
    if((p0.y>lis[i].y)||(p0.y==lis[i].y&&p0.x>lis[i].x)){
        p0=lis[i];
        k=i;
    }
  }
  lis[k]=lis[0];
  lis[0]=p0;
  sort(lis+1,lis+n,cmp);
  if(n==1){
    st[0]=0;
    top=1;
    return;
  }
  if(n==2){
    st[0]=0;
    st[1]=1;
    top=2;
    return;
  }
  st[0]=0;
  st[1]=1;
  top=2;
  for(int i=2;i<n;i++){
    while(top>1&&sgn((lis[st[top-1]]-lis[st[top-2]])^(lis[i]-lis[st[top-2]]))<=0)
        top--;
    st[top++]=i;

  }

}
double dis(Point a,Point b){
return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int main(){
  int n;double l;
  while(scanf("%d%lf",&n,&l)==2){
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&lis[i].x,&lis[i].y);
        //cin>>lis[i].x>>lis[i].y;
    }
    graham(n);
    double ans=0;
    for(int i=0;i<top;i++){
        ans+=dis(lis[st[(i+1)%top]],lis[st[i]]);
       // cout<<ans<<endl;
    }
    ans+=2.0*PI*l;

   printf("%.0lf\n",ans);
  }
  return 0;
}

