#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
double a[maxn];
int main()
{
  int n,w;
 while(cin>>n>>w)
 {
   for(int i=1;i<=2*n;i++)
    cin>>a[i];
   sort(a+1,a+2*n+1);
   double x=a[1];double y=a[n+1];
   double ans=min(x*2,y);
   double result=n*(ans/2.0)+n*ans;
   result=min(double(w),result);
   printf("%.6lf\n",result);
 }
}