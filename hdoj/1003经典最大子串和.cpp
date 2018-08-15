#include<iostream>
#include<cstdio>
using namespace std;
int a[100000];
int f[100000];
int main(){
	int t;
	cin>>t;
	int h=t;
	while(h--){
		int n;
		int l;int x;int y;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		f[0]=a[0];
		for(int i=1;i<n;i++) 
			f[i]=f[i-1]>0?f[i-1]+a[i]:a[i];
		int max=f[0];int index=0;
		for(int i=0;i<n;i++) if(f[i]>max) {max=f[i];index=i;}
		x=f[index];
		for(l=index;l>=0;l--) {x=x-a[l];if(x==0) y=l;}
		printf("Case %d:\n",t-h);
	    printf("%d %d %d\n",f[index],y+1,index+1);
	    if(h!=0) printf("\n");
	}
	return 0;
}
