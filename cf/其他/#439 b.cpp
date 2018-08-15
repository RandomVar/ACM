#include<iostream>
#define ll long long
using namespace std;
int main(){
	ll a,b;
	while(cin>>b>>a){
		if(a-b>=10) cout<<0<<endl;
		else {
			int ans=1;
			for(ll i=a;i>b;i--)
			ans*=i%10;
			  ans=ans%10;
			  cout<<ans<<endl;
		}
	}
	return 0;
}
