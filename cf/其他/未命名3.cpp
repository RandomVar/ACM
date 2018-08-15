#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
ll mul(ll x,ll y,ll Z)//大数相乘取模
{
    ll tmp=x/(long double)Z*y+1e-3;
    return (x*y+Z-tmp*Z)%Z;
}
ll MUL(ll x,ll p,ll Z)
{
    ll y=1;
    while(p)
    {
        if(p&1)y=mul(y,x,Z);
        x=mul(x,x,Z);
        p>>=1;
    }
    return y;
}
bool miller_rabin(ll n)/*为素数为1*/
{
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    ll p=n-1;
    srand(time(NULL));
    int TIMES=8;
    for(int i=1;i<=TIMES;i++)
    {
        ll x=rand()%(n-1)+1;
        if(MUL(x,p,n)!=1)return 0;
    }
    return 1;
}
int panduan(int x){
	if(x!=2&&x%2==0){
		return x/4;
	}
	//if(miller_rabin((ll)x)) return -1;
	if(x<9) return -1;
	if(x==11) return -1;
	x=x-9;
	return x/4+1;
} 
int main(){
   int q;cin>>q;
   while(q--){
   	int x;
   	cin>>x;
   	cout<<panduan(x)<<endl;
   }
   return 0;
}
