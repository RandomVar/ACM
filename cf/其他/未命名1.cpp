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
	int n,m;
	while(cin>>n>>m){
		int Min=10;int Min2=10;int Min1=10;
		int ans=100;vector<int>v;
       vector<int>a;
       vector<int>b;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a.push_back(x);
			Min1=min(Min1,x);
		}
		for(int i=1;i<=m;i++){
		 int x;
		  cin>>x;
		  b.push_back(x);
		   Min2=min(Min2,x);}
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++){
		  	if(a[i]==b[j]) v.push_back(a[i]);
		  }
		if(!v.empty()){
		
		for(int i=0;i<v.size();i++)
		  {
		  	Min=min(Min,v[i]);
		  }
		  cout<<Min<<endl;}  
		else{
		ans=min(Min2,Min1)*10+max(Min2,Min1);
		cout<<ans<<endl;
	}}
} 
