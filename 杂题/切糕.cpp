#include<iostream>
using namespace std;
int digui(int n){
	if(n==1) return 0;
	return digui(n/2)+digui(n-n/2)+n/2*(n-n/2);
}
int main(){
  int t;
  cin>>t;
  while(t--){
  	int n;
  	cin>>n;
  	int t=digui(n);
  	if(t==0) cout<<"Mission Complete!"<<endl;
  	else if(t==1) cout<<"Needs at least 1 ATP!"<<endl;
  	else cout<<"Needs at least " << t << " ATPs!"<<endl;
  }
  return 0;
}
