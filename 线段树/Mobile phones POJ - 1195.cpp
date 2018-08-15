#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int maxn=1100;
int n;
int tree[maxn*3][maxn*3];

void updatey(int kx,int l,int r,int y,int ky,int add){
  tree[kx][ky]+=add;
  if(l==r) return;
  int mid=(l+r)/2;
  if(y<=mid)
     updatey(kx,l,mid,y,ky*2,add);
  else
    updatey(kx,mid+1,r,y,ky*2+1,add);
}

void updatex(int l,int r,int x,int y,int kx,int add){
  updatey(kx,1,n,y,1,add);
  if(l==r) return;
  int mid=(l+r)/2;
  if(x<=mid){
       updatex(l,mid,x,y,kx*2,add);
  }
  else updatex(mid+1,r,x,y,kx*2+1,add);
}
int queryy(int kx,int l,int r,int yl,int yr,int ky){
  if(l>=yl&&r<=yr)
    return tree[kx][ky];
  int cnt=0;
  int mid=(l+r)/2;
  if(yl<=mid) cnt+=queryy(kx,l,mid,yl,yr,ky*2);
  if(yr>mid) cnt+=queryy(kx,mid+1,r,yl,yr,ky*2+1);
  return cnt;
}

int queryx(int l,int r,int xl,int xr,int yl,int yr,int kx){
  if(l>=xl&&r<=xr){
    return queryy(kx,1,n,yl,yr,1);
  }
  int cnt=0;
  int mid=(l+r)/2;
  if(xl<=mid) cnt+=queryx(l,mid,xl,xr,yl,yr,kx*2);
  if(xr>mid) cnt+=queryx(mid+1,r,xl,xr,yl,yr,kx*2+1);
 return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int op;
   mem(tree);
   while(cin>>op){
    if(op==3) break;
    if(op==0)
        cin>>n;
    if(op==1){
        int x,y,a;
        cin>>x>>y>>a;
        updatex(1,n,x+1,y+1,1,a);
    }
    if(op==2){
        int xl,xr,yl,yr;
        cin>>xl>>yl>>xr>>yr;
        cout<<queryx(1,n,xl+1,xr+1,yl+1,yr+1,1)<<endl;
    }

   }

}
