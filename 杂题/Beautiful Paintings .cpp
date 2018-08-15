#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;int a[1005];int b[1005];
		while(cin>>n){
			for(int i=1;i<=n;i++) cin>>a[i];
		    sort(a+1,a+n+1);
		    int k=0;int cnt=0;
		    memset(b,0,sizeof(b));
		    for(int i=2;i<=n;i++) {
		    	int flag=0;
			  while(a[i]==a[i-1]) {i++;b[k]++;flag=1;} k++;
			  if(flag==0) cnt++;}
			int max=0;int max2=0;
		    for(int i=0;i<k;i++) 
			  if(b[i]>max) max=i;
			for(int i=0;i<k;i++)   
			  if(b[i]<=max&&b[i]>max2) max2=i;
		    cnt+=max2;
		    cout<<cnt<<max2<<max<<endl; 
}
return 0;}
