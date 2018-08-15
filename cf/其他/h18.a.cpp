#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
ll powb(int a,int b){
	ll res=1;int x=2;
	while(a){
		if(a&1)
		  res=res*x;
		x=x*x;
		a>>=1;
		if(res>b) return 0;
	}
	return res;
}
ll quickmod(int a,int b,int c){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%c;
		a=a*a%c;
		b>>=1;
	}
	return res;
}
int main(){
  int n,m;
  while(cin>>n>>m){
    if(n>=m) cout<<m<<endl;
    else{ ll x=powb(n,m);
        if(x==0) cout<<m<<endl;
        else {
           // cout<<x<<endl;
            cout<<m%x<<endl;
  }
}}}
