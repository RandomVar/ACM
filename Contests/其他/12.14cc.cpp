/****��⣺ http://blog.csdn.net/SwordHoly/article/details/4423543 ****/

/*mx+ny=c���������㷨

���� m*x+n*y=gcd(x,y)��һ���ؽ� ��d=gcd(x,y)

��� d|c �򷽳��н� ���෴��û�н�

�� �ؽ� x0 y0 t=c/d

���ݶ���ͼ��ֱ���ϵ������㣩 ͨ��Ϊx=t*x0+n/d*u; y=t*y0-m/d*u; uΪ��������

����������С�������� x=x0*t; x=(x%(n/d)+(n/d))%(n/d)

ΪʲôҪ��+n/d

�ڱ����-1%3=-1 ʵ�� -1%3=2
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
