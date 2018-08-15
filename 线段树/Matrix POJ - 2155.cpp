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


const int maxn=1010;
int tree[maxn<<2][maxn<<2];
int n;
void updatey(int kx,int l,int r,int yl,int yr,int ky){
   if(yl<=l&&yr>=r){
     tree[kx][ky]=!tree[kx][ky];
     return;
   }
   int mid=(l+r)/2;
   if(mid>=yl) updatey(kx,l,mid,yl,yr,ky*2);
   if(mid<yr) updatey(kx,mid+1,r,yl,yr,ky*2+1);
}
void updatex(int l,int r,int xl,int xr,int yl,int yr,int kx){//xl,xr is fresh area
 if(xl<=l&&xr>=r){
    updatey(kx,1,n,yl,yr,1);
   return;
 }
 int mid=(l+r)/2;
 if(mid>=xl) updatex(l,mid,xl,xr,yl,yr,kx*2);
 if(mid<xr) updatex(mid+1,r,xl,xr,yl,yr,kx*2+1);
}

int queryy(int kx,int l,int r,int y,int ky){
   int cnt=0;
   if(tree[kx][ky]) cnt++;
   if(l==r) return cnt;
   int mid=(l+r)/2;
   if(y<=mid) cnt+=queryy(kx,l,mid,y,ky*2);
   else cnt+=queryy(kx,mid+1,r,y,ky*2+1);
   return cnt;
}
int queryx(int l,int r,int x,int y,int kx){
   int cnt=0;
   cnt+=queryy(kx,1,n,y,1);
   if(l==r) return cnt;
   int mid=(l+r)/2;
   if(x<=mid) cnt+=queryx(l,mid,x,y,kx*2);
   else cnt+=queryx(mid+1,r,x,y,kx*2+1);
   return cnt;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int x;
  cin>>x;
  while(x--){
    int t;
    cin>>n>>t;
   // cout<<n<<t<<endl;
    memset(tree,0,sizeof(tree));
    int cnt=0;
    for(int i=0;i<t;i++){
        //getchar();
        char ch;
        cin>>ch;
        if(ch=='C'){
               // cout<<ch<<endl;
                int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            updatex(1,n,x1,x2,y1,y2,1);
        }
        else if(ch=='Q'){
            int xx,y;
            cin>>xx>>y;
             if(queryx(1,n,xx,y,1)%2==0) cout<<0<<endl;
             else cout<<1<<endl;
        }
    }
    if(x) cout<<endl;
  }

}
