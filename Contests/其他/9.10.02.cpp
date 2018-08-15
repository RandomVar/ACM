#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int main(){
	ll m,k;
	while(cin>>m>>k){
		ll ans=k*(m-k+1);
		cout<<ans<<endl;
	}
}
