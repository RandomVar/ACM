#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
#include<vector>
using namespace std;
const int maxn=10100;
int val[maxn<<4];
int vis[maxn<<3];
int x[maxn];
int y[maxn];
int ans;
//有多种颜色返回-1；没有颜色返回0 
void pushup(int rt){
	if(val[rt*2]==val[rt*2+1]&&val[rt*2]!=-1) {
		val[rt]=val[rt*2];return;
	}
	else if(val[rt*2]==0&&val[rt*2+1]>0) {
		val[rt]=val[rt*2+1];return;
	}
	else if(val[rt*2+1]==0&&val[rt*2]>0){
		val[rt]=val[rt*2];return;
	}
	else {
		val[rt]=-1;return;
	} 
} 
void pushdown(int rt){
	if(val[rt]==-1) return;
	val[rt*2]=val[rt];
	val[rt*2+1]=val[rt];
	val[rt]=-1;
}
void build(int l,int r,int rt){
  memset(val,0,sizeof(val));
  memset(vis,0,sizeof(vis)); 
}
void update(int ll,int rr,int l,int r,int rt,int k){
	if(ll<=l&&rr>=r) {
		val[rt]=k;return;
	}
	int m=(l+r)/2;
	pushdown(rt);
	if(ll<=m) update(ll,rr,l,m,rt*2,k);
	if(rr>m) update(ll,rr,m+1,r,rt*2+1,k);
	pushup(rt);
//	else update(p<<1,l,mid,x,mid,v),update((p<<1)|1,mid+1,r,mid+1,y,v);
//	else update(ll,m,l,m,rt*2,k),update(m+1,rr,m,r,rt*2+1,k);
}

void query(int l,int r,int rt){
	if(val[rt]!=-1) {
	 if(!vis[val[rt]]) {
	 vis[val[rt]]=1;ans++;}
	 return;
	} 
	if(l==r) return;
	  int m=(l+r)>>1;
	  query(l,m,rt<<1);
	  query(m+1,r,rt<<1|1);
}

int main(){
	int t;cin>>t;
   while(t--)  
    {   
	int n;cin>>n;
        build(1, n, 1);  
        vector<int>v;
       for(int i=1;i<=n;i++)  
            { scanf("%d%d",&x[i],&y[i]);
			  v.push_back(x[i]);
			  v.push_back(y[i]);
		} 
        sort(v.begin(),v.end());
        vector<int>::iterator iter = unique(v.begin(),v.end());
        v.erase(iter,v.end());
		for(int i=1;i<v.size();i++){
		  if(v[i]-v[i-1]>1) v.push_back(v[i-1]+1);
		  }
		sort(v.begin(),v.end());  
    for(int i=1;i<=n;i++){
    	int a=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1;
    	int b=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;
    	update(a,b,1,v.size(),1,i);
	}
	ans=0;
	query(1,v.size(),1);
    printf("%d\n",ans);
      
        }    
    return 0;
} 

