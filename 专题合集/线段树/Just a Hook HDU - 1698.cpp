#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=100010;
int sum[maxn<<2];
int seg[maxn<<2];
void pushup(int rt){
	sum[rt]=sum[rt*2]+sum[rt*2+1];
} 
void pushdown(int len,int rt){
	if(seg[rt]==0) return;
	sum[rt*2]=seg[rt]*(len-len/2);
	sum[rt*2+1]=seg[rt]*(len/2);
	seg[rt*2]=seg[rt];
	seg[rt*2+1]=seg[rt];
	seg[rt]=0;
}
void build(int l,int r,int rt){
	if(l==r) {
	 seg[rt]=0;sum[rt]=1;return;}
	int m=(l+r)/2;
	build(l,m,rt*2);
	build(m+1,r,rt*2+1);
	pushup(rt);
	/*
	seg[rt]=0;
	sum[rt]=r-l+1;
	if(l==r) return;
	int m=(r+l)/2;
	build(l,m,rt*2);
	build(m+1,r,rt*2+1);*/
}
void update(int ll,int rr,int l,int r,int rt,int val){
	if(ll<=l&&rr>=r) {
		seg[rt]=val;sum[rt]=val*(r-l+1);return;
	}
	int m=(l+r)/2;
	pushdown(r-l+1,rt);
	if(ll<=m) update(ll,rr,l,m,rt*2,val);
	if(rr>m) update(ll,rr,m+1,r,rt*2+1,val);
	pushup(rt);
}
int query(int ll,int rr,int l,int r,int rt){
	if(ll<=l&&rr>=r) return sum[rt];
	int ans=0;
	int m=(l+r)>>1;
	if(ll<=m) ans+=query(ll,rr,l,m,rt<<1);
	if(rr>m) ans+=query(ll,rr,m+1,r,rt<<1|1);
	return ans;
}
int main(){
	int t;cin>>t;  int k=0;
   while(t--)  
    { k++;   
	int n,m;cin>>n>>m;
        build(1, n, 1);  
       for(int i=0;i<m;i++)  
        {  
            int x, y,z;  
            scanf("%d%d%d", &x, &y,&z);  
            update(x, y, 1, n,1,z);  
               
            }  
    printf("Case %d: The total value of the hook is %d.\n",k,query(1,n,1,n,1));
      
        }    
    return 0;
} 

