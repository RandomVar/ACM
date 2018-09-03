#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f; 
ll h[20];
ll l[20];
struct node{
	int l,r;
}p[30];
void init(){
	h[1]=1;l[1]=1;
	for(int i=2;i<20;i++){
		h[i]=h[i-1]*(4*i-2)/(i+1);
		l[i]=l[i-1]+h[i];
	}
}
void solve(int rt,int a,int x){
	if(a==0) return;
	if(x==0) return;
	//p[rt].l=p[rt].r=-1;
	ll ff=0;
	for(int i=a-1;i>=0;i--){//右子树i个结点 
		int j=a-i-1;
		ff+=h[i]*h[j];
		if(ff>=x){
			ff=x-ff+h[i]*h[j];//右为i，左为j的第几个 
			ff--; 
			if(i) p[rt].r=rt+j+1;
			//cout<<i<<endl;
	        if(j) p[rt].l=rt+1;
	        //cout<<j<<endl;
			solve(rt+1,j,ff/(h[i])+1);
			ff++;
			ll aa=ff%h[i];
			if(aa==0) aa=h[i]; 
			solve(rt+j+1,i,aa);
			return;
		}
	}

}
void dfs(int i){
	if(p[i].l!=-1)
	  {
	  	printf("(");
	  	dfs(p[i].l);
	  	printf(")");
	  }
	printf("X");
	if(p[i].r!=-1){
		printf("(");
		dfs(p[i].r);
		printf(")");
	}
}
int main(){
	freopen("out.txt","w",stdout);
	init();
	h[0]=l[0]=1;
	int n;
    while(cin>>n){
    	if(n==0) break;
    	int k;
    	for(int i=0;i<20;i++){
    		if(n<=l[i]){
    			k=i;break;
			}
		}
		cout<<k<<endl;
		for(int i=0;i<30;i++){
			p[i].l=p[i].r=-1;
		}
		solve(0,k,n-l[k-1]);
	dfs(0);
	printf("\n");
	}
} 
