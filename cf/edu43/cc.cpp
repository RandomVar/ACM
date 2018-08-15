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
const int maxn=3*1e5;
struct node{
 int l,r,id;
 bool operator<(const node &b)const{
 if(l==b.l) return r>b.r;
 return l<b.l;
 }
}a[maxn+10];
int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(scanf("%d",&n)==1){
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
        //cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }
    sort(a,a+n);
    int ii=-1,jj=-1;
    for(int i=0;i<n-1;i++){
            if(a[i].r>=a[i+1].r) {ii=a[i].id;jj=a[i+1].id;break;}
    }
    if(ii!=-1) printf("%d %d\n",jj+1,ii+1);
    else printf("-1 -1\n");
    /*if(ii!=-1) cout<<jj+1<<" "<<ii+1<<endl;
    else cout<<"-1 -1"<<endl;*/
  }
}
