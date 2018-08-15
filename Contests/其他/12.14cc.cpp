/****详解： http://blog.csdn.net/SwordHoly/article/details/4423543 ****/

/*mx+ny=c的整数解算法

先求 m*x+n*y=gcd(x,y)的一个特解 设d=gcd(x,y)

如果 d|c 则方程有解 ，相反则没有解

记 特解 x0 y0 t=c/d

根据丢番图（直线上的整数点） 通解为x=t*x0+n/d*u; y=t*y0-m/d*u; u为任意整数

所以若求最小正整数解 x=x0*t; x=(x%(n/d)+(n/d))%(n/d)

为什么要加+n/d

在编程中-1%3=-1 实际 -1%3=2
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;return a;
	}
	long long ans=exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-a/b*y;
	return ans;
}
int main(){
  ll a,b,c;
  while(cin>>a>>b>>c){

	ll t,u;
		long long d=exgcd(a,b,t,u);
		 if(c%d) cout<<"No"<<endl;
		 else{
        long long s=b/d;
         s=s>0?s:-1*s;
        t=t*c/d;
        t=(t%s+s)%s;
        u=(c-a*t)/b;
        if(t>=0&&u>=0)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}}
	return 0;
}
