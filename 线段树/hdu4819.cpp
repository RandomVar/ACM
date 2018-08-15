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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=810;
int xl,xr,yl,yr;
int n,amin,amax;
int mat[maxn][maxn];
int trmin[maxn>>2][maxn>>2];
int trmax[maxn>>2][maxn>>2];
void pushupy(int xrt,int rt){
   trmax[xrt][rt]=max(trmax[xrt][rt*2],trmax[xrt][rt*2+1]);
   trmin[xrt][rt]=min(trmin[xrt][rt*2],trmin[xrt][rt*2+1]);

}
void updatey(int x,int xrt,int val,int l,int r,int rt){
  if(l==r){
    if(x!=-1){
     trmin[xrt][rt]=val;
     trmax[xrt][rt]=val;
    }
    else{//pushupx
        trmin[xrt][rt]=min(trmin[xrt*2][rt],trmin[xrt*2+1][rt]);
        trmax[xrt][rt]=max(trmax[xrt*2][rt],trmax[xrt*2+1][rt]);
    }
    return;
    }
     int mid=(l+r)/2;
     if(yl<=mid)
          updatey(x,xrt,val,lson);
      else
        updatey(x,xrt,val,rson);
      pushupy(xrt,rt);
}
void updatex(int val,int l,int r,int rt){

   if(l==r) {
        updatey(0,rt,val,1,n,1);
        return;
        }
   int mid=(l+r)/2;
   if(xl<=mid)
    updatex(val,lson);
  else
    updatex(val,rson);
  updatey(0,rt,val,1,n,1);
}

void queryy(int xrt,int l,int r,int rt){
   if(l>=yl&&r<=yr){
     amin=min(amin,trmin[xrt][rt]);
     amax=max(amax,trmax[xrt][rt]);
     return;
 }
  int mid=(l+r)/2;
  if(yl<=mid)
      queryy(xrt,lson);
   if(yr>mid)
    queryy(xrt,rson);
}

void queryx(int l,int r,int rt){
   if(l>=xl&&r<=xr){
     queryy(rt,1,n,1);
     return;
   }
 int mid=(l+r)/2;
 if(xl<=mid)
      queryx(lson);
 if(xr>mid)
    queryx(rson);
  }

void buildy(int xrt,int kx,int l,int r,int rt){
    if(l==r){
      if(kx!=-1)
        trmin[xrt][rt]=trmax[xrt][rt]=mat[kx][l];
      else{
        trmax[xrt][rt]=max(trmax[xrt*2][rt],trmax[xrt*2+1][rt]);
        trmin[xrt][rt]=min(trmin[xrt*2][rt],trmin[xrt*2+1][rt]);
      }
      return;
    }
    int mid=(l+r)/2;
    buildy(xrt,kx,lson);
    buildy(xrt,kx,rson);
    pushupy(xrt,rt);
}
void buildx(int l,int r,int rt){
  if(l==r){
     buildy(rt,l,1,n,1);
     return;
  }
  int mid=(l+r)/2;
   buildx(lson);
   buildx(rson);
   buildy(rt,-1,1,n,1);
}
int main(){
  int t;
  scanf("%d",&t);
  int cas=0;
  while(t--){
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&mat[i][j]);
     }
      printf("Case #%d:\n",++cas);
     //cout<<"Case #"<<++cas<<":"<<endl;
     buildx(1,n,1);
     int q;
      scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        amin=INF;amax=-INF;
               l=(l+1)/2;
            xl=max(1,x-l+1),xr=min(n,x+l-1);
            yl=max(1,y-l+1),yr=min(n,y+l-1);
        /*xl=max(1,x-z/2);xr=min(n,x+z/2);
        yl=max(1,y-z/2);yr=min(n,y+z/2);
        */
       //cout<<xl<<xr<<yl<<yr<<endl;
       queryx(1,n,1);
        xl=x;yl=y;
        int val=(amin+amax)/2;
        printf("%d\n",val);
      updatex(val,1,n,1);
      //cout<<amin<<" "<<amax<<endl;
   }
  }
  return 0;
  }
