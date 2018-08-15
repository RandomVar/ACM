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
const int maxn=2*1e5+100;
int a[maxn],cnt[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m){
   int index=0;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==m) index=i; 
   }
   cnt[index]=0;
   map<int,int>c;
   map<int,int>d;
   //map<int,int>num;
  ll ans=0;
  c[0]=1;d[0]=1;
   for(int i=index+1;i<=n;i++){
       if(a[i]<m) cnt[i]=cnt[i-1]+1;
          else cnt[i]=cnt[i-1];
        int t=(i-index-cnt[i])-cnt[i];//big - small 
       c[t]++;
      /* t=(i-index+2)/2-cnt[i];
     if(t==1) ans++;
     //num[t]++;
     */
   }
  for(int i=index-1;i>0;i--){
     if(a[i]<m)  cnt[i]=cnt[i+1]+1;
     else cnt[i]=cnt[i+1];
      int t=index-i-cnt[i]-cnt[i];
     d[t]++;
    
    // num[t]++;
  }
  map<int,int>::iterator it;

  for(it=c.begin();it!=c.end();it++){
     int t=-it->first;
     if(d.find(t)!=d.end()){
         ans+=(ll)it->second*d[t];
     }
     t++;
     if(d.find(t)!=d.end()){
        ans+=(ll)it->second*d[t];
     }
  }

  
  cout<<ans<<endl;
  

  }


  }

