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
int tree[maxn<<2][maxn<<2];
void updatey(int kx,int l,int r,int yl,int yr,int ky,int val){
   if(l>=xl&&r<=xr){
     tree[kx][ky]=val;
     return;
   }
   int mid=(l+r)/2;
   if(yl<=mid) updatey(kx,l,mid,yl,yr,ky*2,val);
   if(yr>mid)  updatey(kx,mid+1,r,yl,yr,ky*2+1,val);
}
void updatex(int l,int r,int xl,int xr,int yl,int yr,int kx,int val){
   if(l>=xl&&r<=xr){
    updatey(kx,1,n,yl,yr);
    return;
   }
   int mid=(l+r)/2;
   if(xl<=mid) updatex(l,mid,xl,xr,yl,yr,kx*2);
    if(xr>mid) updatex(mid+1,l,xl,xr,yl,yr.kx*2+1);
}
int query()
int main(){
  int t;
  cin>>t;
  mem(tree);
  while(t--){
    string s;
    cin>>s;
    if(s=="BLACK"){
        int x,y,l;
        cin>>x>>y>>l;
        update(1,100,x,x+l-1,y,y+l-1,0);
    }
    if(s=="WHITE"){
        int x,y,l;
        cin>>x>>y>>l;
        update(1,100,x,x+l-1,y,y+l-1,1);
    }
    if(s=="TEST"){
        int x,y,l;
        cin>>x>>y>>l;
        que
    }
  }

}
