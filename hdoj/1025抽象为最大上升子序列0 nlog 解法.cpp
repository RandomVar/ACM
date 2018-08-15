#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int d[500010];
int ans[500010];
int len;
int binary_search(int i){  
    int left,right,mid;  
    left=0,right=len;  
    while(left<right){  
        mid = left+(right-left)/2;  
        if(ans[mid]>=d[i]) right=mid;  
        else left=mid+1;  
    }  
    return left;  
}  
int main(){
	int n;int k=0;
	while(cin>>n){
		k++;
	   memset(ans,0,sizeof(ans));
	  for(int i=0;i<n;i++){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
	    d[t1]=t2;}
	    ans[1]=d[1];
	    len=1;
	  for(int i=2;i<=n;i++)	{
	  	if(d[i]>ans[len]) ans[++len]=d[i];
	  	else {
	  		int pos=binary_search(i); 
                ans[pos] = d[i]; 
		  }
	  }
	  printf("Case %d:\n",k);
	  if(len>1) printf("My king, at most %d roads can be built.\n\n",len);
	  else if(len==1) printf("My king, at most 1 road can be built.\n\n");
	}
	return 0;
} 
