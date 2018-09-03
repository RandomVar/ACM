#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=810;
int tree[maxn<<2][maxn<<2];
int tree2[maxn<<2][maxn<<2];
int mat[maxn][maxn];
int n;int ansmin;int ansmax;
void pushupy(int rx,int ry){
  tree[rx][ry]=max(tree[rx][ry*2],tree[rx][ry*2+1]);
  tree2[rx][ry]=min(tree2[rx][ry*2],tree2[rx][ry*2+1]);
}
void queryy(int rx,int l,int r,int yl,int yr,int ry){//l,r为当前边界
 if(l>=yl&&r<=yr) {
    ansmax=max(ansmax,tree[rx][ry]);
    ansmin=min(ansmin,tree2[rx][ry]);
    return;
 }

 int mid=(l+r)/2;
 if(yl<=mid){
   queryy(rx,l,mid,yl,yr,ry*2);
 }
 if(yr>mid){
  queryy(rx,mid+1,r,yl,yr,ry*2+1);
 }
}

void queryx(int l,int r,int xl,int xr,int yl,int yr,int rx){//l,r为当前边界
 if(l>=xl&&r<=xr) {
   queryy(rx,1,n,yl,yr,1);
   return;
 }
 int mid=(l+r)/2;
 if(xl<=mid){
      queryx(l,mid,xl,xr,yl,yr,rx*2);
 }
 if(xr>mid){
    queryx(mid+1,r,xl,xr,yl,yr,rx*2+1);
 }
}

void updatey(int x,int l,int r,int ky,int val,int rx,int ry){
  if(l==r){
    if(x!=-1){
     tree[rx][ry]=val;
     tree2[rx][ry]=val;
    }
    else{//pushupx
        tree[rx][ry]=max(tree[rx*2][ry],tree[rx*2+1][ry]);
        tree2[rx][ry]=min(tree[rx*2][ry],tree[rx*2+1][ry]);
    }
     return;

  }
  int mid=(l+r)/2;
  if(ky<=mid){
    updatey(x,l,mid,ky,val,rx,ry*2);
  }
  else updatey(x,mid+1,r,ky,val,rx,ry*2+1);
  pushupy(rx,ry);
}

void updatex(int l,int r,int kx,int ky,int val,int rx){
  if(l==r) {
    updatey(0,1,n,ky,val,rx,1);
    return;
  }
  int mid=(l+r)/2;
  if(kx<=mid){
    updatex(l,mid,kx,ky,val,rx*2);
  }
  else updatex(mid+1,r,kx,ky,val,rx*2+1);
  updatey(-1,1,n,ky,val,rx,1);
}
void buildy(int x,int kx,int rx,int l,int r,int ry){
  if(l==r){
    if(x!=-1)
     tree[rx][ry]=tree2[rx][ry]=mat[kx][l];
    else{
        tree[rx][ry]=max(tree[rx*2][ry],tree[rx*2+1][ry]);
        tree2[rx][ry]=min(tree2[rx*2][ry],tree2[rx*2+1][ry]);
    }
     return;
  }
  int mid=(l+r)/2;
  buildy(x,kx,rx,l,mid,ry*2);
  buildy(x,kx,rx,mid+1,r,ry*2+1);
  pushupy(rx,ry);
}
void buildx(int l,int r,int rx){
  if(l==r){
    buildy(0,l,rx,1,n,1);
    return;
  }
  int mid=(l+r)/2;
  buildx(l,mid,rx*2);
  buildx(mid+1,r,rx*2+1);
  buildy(-1,l,rx,1,n,1);
}
int main(){
  int t;
  cin>>t;int cas=0;
  while(t--){
//     int n;
     cin>>n;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>mat[i][j];
//        updatex(1,n,x,y,val,1);
     }
//     mem(tree2);
     cout<<"Case #"<<++cas<<":"<<endl;
   buildx(1,n,1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y,l;
        cin>>x>>y>>l;
        ansmin=INF;ansmax=-INF;
        int x1=max(1,x-l/2);int x2=min(n,x+l/2);int y1=max(1,y-l/2);int y2=min(n,y+l/2);
        queryx(1,n,x1,x2,y1,y2,1);
        updatex(1,n,x,y,(ansmin+ansmax)/2,1);
       cout<<(ansmin+ansmax)/2<<endl;
    }
  }

}
