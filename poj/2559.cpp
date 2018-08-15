#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
struct stack{
	int height;
	int id;
}st[100005];
ll h[100005]; 
int main(){
	int n;
	while(cin>>n&&n!=0){
		for(int i=1;i<=n;i++)  {
		cin>>h[i];
	}
	st[1].height=h[1];
	st[1].id=1;
	int top=1;
	int ans=0;
	h[n+1]=0;
	for(int i=2;i<=n+1;i++){
		if(h[i]>=st[top].height){
			++top;
			st[top].height=h[i];
			st[top].id=i;
		}
		else{
			while(top>=0&&st[top].height>h[i]){
				ll tmp=(i-st[top].id)*st[top].height;
				if(tmp>ans) ans=tmp;
				top--;
			}
			top++;
			st[top].height=h[i];
		}
	}
	printf("%lld\n",ans);
}
return 0;}
