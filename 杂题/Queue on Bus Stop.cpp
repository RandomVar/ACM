#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int n,m;
	int a[105];
	while(cin>>n>>m){
		int cnt=1;
		for(int i=0;i<n;i++) cin>>a[i];
		int s=m;
		for(int i=0;i<n;i++){
			if(a[i]<=s) {s-=a[i];}
			else if(a[i]>s) {cnt++;s=m-a[i];}
		}
		cout<<cnt<<endl;
	}
}
