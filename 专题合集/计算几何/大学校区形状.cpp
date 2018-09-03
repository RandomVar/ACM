#include<bits/stdc++.h>
using namespace std;
struct point{
 int x,y;
}p[110];
int multi(point p1,point p2,point p0){
 return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

int main(){
   int n;
   while(cin>>n){
    if(n==0) break;
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    int flag=0;
   for(int i=0;i<n;i++){
    int t=multi(p[i],p[(i+2)%n],p[(i+1)%n]);
    if(t>0) {
        flag=1;break;
    }
   }
   if(flag) cout<<"concave"<<endl;
   else cout<<"convex"<<endl;
   }
}
