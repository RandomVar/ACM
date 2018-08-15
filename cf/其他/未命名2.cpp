#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int a[100010];
int main(){
	int n,k;
	while(cin>>n>>k){
		int Max=-INF;int Min=INF;
		int x;
		for(int i=0;i<n;i++)
		  {
		  cin>>a[i];
		  if(a[i]>Max){
		  Max=a[i];x=i;}
		  Min=min(a[i],Min);} 
		if(k==1) cout<<Min<<endl;
		else if(k==2&&x!=0&&x!=n-1) {
			//cout<<x<<endl; 
		cout<<max(a[0],a[n-1])<<endl; 
			
		}
		else cout<<Max<<endl;
	}
}
