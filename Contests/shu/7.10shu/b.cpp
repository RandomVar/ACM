#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
struct node{
   string s;
   double t1,t2;
bool operator<(const node &b) const{
  return t2<b.t2;
}
}a[600];
int da[10];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n){
      for(int i=0;i<n;i++){
          cin>>a[i].s>>a[i].t1>>a[i].t2;
        // sum1+=a[i].t2;
      }
      sort(a,a+n);
      double daan=inf;
      for(int i=0;i<3;i++){
           double ans=a[i].t1;
           for(int j=0;j<4;j++){
              if(j!=i)
                ans+=a[j].t2;
           }
           if(daan>ans){
               daan=ans;
                da[0]=i;
                int k=0;
              for(int j=0;j<4;j++){
                  if(j!=i)
                    da[++k]=j;
              }
           }
      }
      double ans=0;
      for(int j=0;j<3;j++)
        ans+=a[j].t2;
      double mi=inf;int idex=-1;
      for(int i=3;i<n;i++){
        if(mi>a[i].t1) {mi=a[i].t1;idex=i;}
      }
      ans+=a[idex].t1;
      if(ans<daan){
         cout<<ans<<endl;
         cout<<a[idex].s<<endl;
         for(int i=0;i<3;i++)
           cout<<a[i].s<<endl;

      }
      else{
        cout<<daan<<endl;
        for(int i=0;i<4;i++)
          cout<<a[da[i]].s<<endl;

      }
   }


  }

