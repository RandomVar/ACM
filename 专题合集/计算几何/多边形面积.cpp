#include<bits/stdc++.h>
using namespace std;
struct point{
  int x,y;
}points[50];
int multi(point p1,point p2,point p0){
 return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int main(){
  int n;int k=0;
  while(scanf("%d",&n)==1){
      k++;
    for(int i=0;i<n;i++){
        scanf("%d%d",&points[i].x,&points[i].y);
        //cin>>points[i].x>>points[i].y;
    }
    double ans=0;
    for(int i=1;i<n-1;i++){
        ans+=multi(points[i],points[i+1],points[0]);
    }
    //ans=fabs(ans);
    printf("Case %d:%.1lf\n",k,fabs(ans/2));
  }
}
