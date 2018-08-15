#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int build(){
	int w1,d1,w2,d2;
	cin>>w1>>d1>>w2>>d2;
	int left;int right;
	if(w1==0){
		int t=build();
		if(t==-1) left=-1;
		else left=t*d1;
	}
	else left=w1*d1;
	if(w2==0){
		int t=build();
		if(t==-1) right=-1;
		else right=t*d2;
	}
	else right=w2*d2;
	if(right==left&&right!=-1) return left/d1+right/d2;
    return -1; 
}
int main(){
	int n;
	cin>>n;
	while(n--){
		 if(build()==-1) cout<<"NO"<<endl;
		 else cout<<"YES"<<endl;
		 if(n!=0) cout<<endl;
	}
	return 0;
} 
