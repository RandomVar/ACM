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
const ll INF=1e18;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int l[100010],e[100010];
int main(){
  int n,m,cl,ce,v;
  while(cin>>n>>m>>cl>>ce>>v){
      for(int i=0;i<cl;i++)
        cin>>l[i];
      for(int i=0;i<ce;i++)
        cin>>e[i];
      int q;
      cin>>q;
      ll ans=INF;
      ll ans2=INF;
      ll ans3=INF;
      for(int i=0;i<q;i++){
        int flag=0;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(y2<y1) swap(y2,y1);
        if(x1==x2) cout<<abs(y2-y1)<<endl;
        else{
      if(ce&&x1<x2){
        int p1=lower_bound(e,e+ce,y1)-e;//>=x1
        if(p1!=ce&&e[p1]>=y1&&e[p1]<=y2) {ans=y2-y1+(abs(x2-x1)+v-1)/v;}
        else if(p1==ce) ans2=y1+y2-2*e[p1-1];
        else if(p1) ans2=min(2*e[p1]-y1-y2,y1+y2-2*e[p1-1]);
        else if(p1==0) ans2=2*e[p1]-y1-y2;
        ans=min(ans,ans2+(abs(x2-x1)+v-1)/v);}
       // cout<<ans<<endl;
        if(cl){
        int p2=lower_bound(l,l+cl,y1)-l;
        if(p2!=cl&&l[p2]>=y1&&l[p2]<=y2) ans3=y2-y1;
        else if(p2==cl) ans3=y1+y2-2*l[p2-1];
        else if(p2) ans3=min(2*l[p2]-y1-y2,y1+y2-2*l[p2-1]);
        else if(p2==0) ans3=2*l[p2]-y1-y2;
        //cout<<p2<<endl;
        ans=min(ans,ans3+abs(x2-x1));
      }
        cout<<ans<<endl;
      }}
  }

}
