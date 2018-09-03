#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int b[40010];
int a[40010];
int partition(int low,int high,int key){
	while(low<=high){
		int mid=(low+high)/2;
		if(key<b[mid]) high=mid-1;
		else low=mid+1;
	}
	return low;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		int len=1;
		b[len]=a[0];
	    for(int i=1;i<n;i++){
	    	if(a[i]>b[len]){
	    		len++;b[len]=a[i];
			}
			else {
				int pos=partition(1,len,a[i]);
				b[pos]=a[i];
			}
		}
		printf("%d\n",len);
	}
}
