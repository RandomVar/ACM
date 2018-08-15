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
typedef pair<ll,int>p;
const int maxn=1e5+100;
int m;
int a[5];
int b[5],bb[5];
int v[maxn];
vector<p>vec;
int cal(int x){
    int i=x/3;
    int j=x%3;
     if(i==j)
     {
         if(bb[i]>=2)
             {bb[i]-=2;return 1;}
        return 0;
     }
     if(bb[i]&&bb[j])
        {bb[i]--,bb[j]--;return 1;}
    else return 0;

}
int check(ll x){
     for(int i=0;i<3;i++) bb[i]=b[i];
  for(int k=0;k<m;k++){
      //int flag=0;
       int i=0;
      for(i=0;i<6;i++){
            if(vec[i].first*v[k]>=x){
               if(cal(vec[i].second)) break;        
               }
        }
      if(i==6) return 0;
      }
return 1;
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   while(cin>>b[0]>>b[1]>>b[2]){
       m=(b[0]+b[1]+b[2])/2;
       for(int i=0;i<3;i++)
         cin>>a[i];
      for(int i=0;i<m;i++)
        cin>>v[i];
      sort(v,v+m);
      vec.clear();
      for(int i=0;i<3;i++)
        for(int j=i;j<3;j++)
           vec.pb(make_pair(a[i]+a[j],i*3+j));
        sort(vec.begin(),vec.end());
       ll l=0;ll r=1e9;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid)) 
               l=mid+1;
            else r=mid-1;
        }
         cout<<l-1<<endl;

   }


  }

