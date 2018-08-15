#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn=2000000000;
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
bool miller_rabin(ll n)
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
int main(){
	ll n;
	while(cin>>n){
    //cout<<miller_rabin(n)<<endl;
	if(miller_rabin(n)) cout<<"1"<<endl;
	else if(n%2==0) cout<<"2"<<endl;
	else if(miller_rabin(n-2)) cout<<"2"<<endl;
	else cout<<"3"<<endl;
}
return 0;
}
