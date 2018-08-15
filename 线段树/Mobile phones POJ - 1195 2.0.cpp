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
int low_bit(int x){
return x&(-x);
}
void update(int x,int y,int add){
   for(int i=x;i<=n;i+=low_bit(i))
     for(int j=y;j<=n;j+=low_bit(j))
        tree[i][j]+=add;
}
int sum(int x,int y){
    int res=0;
  for(int i=x;i>0;i-=low_bit(i))
    for(int j=y;j>0;j-=low_bit(j))
      res+=tree[i][j];
return res;
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
        update(x+1,y+1,a);
    }
    if(op==2){
        int xl,xr,yl,yr;
        cin>>xl>>yl>>xr>>yr;
        int ans=0;
        ans+=sum(xr+1,yr+1);
        ans+=sum(xl,yl);
        ans-=sum(xl,yr+1);
        ans-=sum(xr+1,yl);
    cout<<ans<<endl;}
   }

}
