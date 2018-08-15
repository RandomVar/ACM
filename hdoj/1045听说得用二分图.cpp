#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int map[7][7];
int main(){
	int n;
	while(cin>>n&&n!=0){
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++) {
			getchar();
		  for(int j=0;j<n;j++)
		     { char a;cin>>a;
		       if(a=='.') map[i][j]=0;
		       else if(a=='X') map[i][j]=1;}
	}
	/*for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++)
	   cout<<map[i][j];
	   cout<<endl;}
	  */ 
	int k=0;int cnt=0;
	while(k<n){
		  for(int i=k,j=0;j<=k;j++)
		    if(map[i][j]==0){
		    	int flag=0;
		    	for(int t=i;t>=0&&map[t][j]!=1;t--)
		    	  if(map[t][j]==-1) flag=1;
		    	for(int t=j;t<=k&&map[i][t]!=1;t++)
		    	  if(map[i][t]==-1) flag=1;
		    	for(int t=j;t>=0&&map[i][t]!=1;t--)
		    	  if(map[i][t]==-1) flag=1;
		    	if(flag==0) {map[i][j]=-1;cnt++;}
			}
			//cout<<cnt<<endl;
		  for(int j=k,i=0;i<=k;i++)
		    if(map[i][j]==0){
		    	int flag=0;
		    	for(int t=i;t<=k&&map[t][j]!=1;t++)
		    	  if(map[t][j]==-1) flag=1;
		    	for(int t=i;t>=0&&map[t][j]!=1;t--)
		    	  if(map[t][j]==-1) flag=1;
		    	for(int t=j;t>=0&&map[i][t]!=1;t--)
		    	  if(map[i][t]==-1) flag=1;
		    	if(flag==0) {map[i][j]=-1;cnt++;}
			}
			//cout<<cnt<<endl;
			k++;
	}
	cout<<cnt<<endl;
	}
}
