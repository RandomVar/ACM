#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll a[100010]; 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		ll max=0;ll min=0x3f3f3f3f;
		for(int i=0;i<n;i++) {
		 cin>>a[i];if(a[i]>max) max=a[i];if(a[i]<min) min=a[i];}
		ll k;ll mid; 
		cin>>k;
		if(k==1) min=max;
		if(k>1){
			min=min/(k-1);
		while(min<=max){
			int flag=0;ll t=0;
			mid=(min+max)>>1;
			for(int i=0;i<n;i++){
				ll more=a[i]-mid;
				if(more>0){
				 t+=(more+k-2)/(k-1);
				 if(t>mid) {flag=1;break;}
			}}
			if(flag==1) min=mid+1;
			else max=mid-1;
		}}
		printf("%lld\n",min);
	}
}
