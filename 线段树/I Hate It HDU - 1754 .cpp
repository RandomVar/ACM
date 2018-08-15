#include<iostream>
#include<cstdio> 
#include<cmath>
using namespace std;
const int maxn = 200100;  
int s[maxn << 2]; 
void pushup(int rt){
	s[rt]=max(s[rt<<1],s[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r) {
	scanf("%d",&s[rt]);return;}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(int p,int add,int l,int r,int rt){
	if(l==r) {
	 s[rt]=add;return;}
	int m=(l+r)>>1;
	if(p<=m) update(p,add,l,m,rt<<1);
	else update(p,add,m+1,r,rt<<1|1);
	pushup(rt);
}
int query(int ll,int rr,int l,int r,int rt){
	if(ll<=l&&rr>=r) return s[rt];
	int ans=0;
	int m=(l+r)>>1;
	if(ll<=m) ans=max(ans,query(ll,rr,l,m,rt<<1));
	if(rr>m) ans=max(ans,query(ll,rr,m+1,r,rt<<1|1));
	return ans;
}
int main(){
	int n, m;  
    char d[10];  
   while(scanf("%d%d",&n,&m)==2)  
    {  
        build(1, n, 1);  
       for(int i=0;i<m;i++)  
        {  
           scanf("%s",d); 
            int x, y;  
            scanf("%d%d", &x, &y);  
            if (d[0] == 'Q')  
            {  
                int ans = query(x, y, 1, n, 1);  
                printf("%d\n", ans);  
            }  
            if (d[0] == 'U') update(x, y, 1, n, 1);   
        }  
    }  
    return 0;
} 
