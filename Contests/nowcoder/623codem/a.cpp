#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int mp[550][550];
struct node{
  int x,y,z;
  double t;
  bool operator<(const node &b){
  if(t==b.t) return z>b.z;
    return t<b.t;
  }
}a[110000];
int main(){
   int n,m,k;
   while(cin>>n>>m>>k){
      for(int i=0;i<k;i++){
          string t;
          cin>>a[i].x>>a[i].y>>a[i].z>>t;
          for(int j=0;j<t.size();j++)
             if(t[j]==':') t[j]=' ';
           stringstream ss(t);
           int h,m;double s;
          ss>>h;ss>>m;ss>>s;
         // printf("%lf",s);
         a[i].t=h*60*60+m*60+s;
        // cout<<a[i].t<<endl;
      }
   sort(a,a+k);
   memset(mp,0,sizeof(mp));
   int ans=0;int index=0;int cnt=0;
   for(int i=0;i<k;i++){
       if(a[i].z==0) {
            mp[a[i].x][a[i].y]++;
            if( mp[a[i].x][a[i].y]==1)
            {
                ans++;
              if(ans>=cnt) {cnt=ans;index=i;}
            }
       }
       else{
            mp[a[i].x][a[i].y]--;
            if( mp[a[i].x][a[i].y]==0)
            {
                ans--;

            }
   }
   }
   memset(mp,0,sizeof(mp));
  //cout<<index<<endl;
   for(int i=0;i<=index;i++){
       if(a[i].z==0) mp[a[i].x][a[i].y]++;
       else mp[a[i].x][a[i].y]--;
   }
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      if(mp[i][j]) cout<<1;
      else cout<<0;
      cout<<endl;}
   }
}
