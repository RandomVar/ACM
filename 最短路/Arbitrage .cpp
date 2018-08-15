#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
double cost[40][40];
map<string,int>name;
void floyd(int n){
	for(int k=1;k<=n;k++)
		  for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++)
		      cost[i][j]=max(cost[i][j],cost[i][k]*cost[k][j]);
}
int main(){
	int n;int t=0;
	while(cin>>n&&n){
		t++;
		for(int i=1;i<=n;i++){
			string s;
		  cin>>s;
		  name[s]=i;}
		int m;cin>>m;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    cost[i][j]=1;
		    
		for(int i=1;i<=m;i++){
		  string str1;string str2; double a;
		  cin>>str1; cin>>a; cin>>str2;
		  cost[name[str1]][name[str2]]=a;
		}
		floyd(n);int flag=0;
		for(int i=1;i<=n;i++)
		  if(cost[i][i]>1) {
		  	flag=1;break;
		  }
	   cout<<"Case "<<t<<": ";
	   if(flag==1) cout<<"Yes"<<endl;
	   else cout<<"No"<<endl;
	}
}
