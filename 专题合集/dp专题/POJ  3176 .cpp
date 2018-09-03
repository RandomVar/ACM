#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int a[400][400];
int main(){
	int n;
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=i;j++)
		    cin>>a[i][j];
		for(int i=n-1;i>=1;i--)
		  for(int j=1;j<=i;j++)
		   a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
	/*	for(int i=1;i<=n;i++){
		  for(int j=1;j<=i;j++)
		    cout<<a[i][j]<<" ";
		    cout<<endl;}*/
		cout<<a[1][1]<<endl;
	}
}
