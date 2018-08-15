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
const int maxn=12*1e4+100;
ll b[40];
void init(){
    b[0]=1;
   for(int i=1;i<34;i++)
     b[i]=b[i-1]*2;
}
ll a[maxn];
int vis[maxn];
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n;
 init();
 while(scanf("%d",&n)==1){
   for(int i=0;i<n;i++)
     scanf("%lld",&a[i]);
     //cin>>a[i];
     int cnt=0;
   sort(a,a+n);
   mem(vis,0);
   for(int i=0;i<n;i++)
   {
     if(!vis[i]){
           for(int j=0;j<34;j++)
           {
                 ll x=b[j]-a[i];
                 if(x<0) continue;
                 if(x>1e9) break;
                int p=lower_bound(a,a+n,x)-a;
                //  cout<<p<<" "<<x<<endl;
                if(p==i) {
                    if(p+1==n||a[p+1]!=x) continue;
                    else{
                         vis[i]=1;vis[p+1]=1;continue;
                    }
                  
                    }
                    if(p==n) break;
                if(a[p]!=x) continue;
                else {vis[i]=1;vis[p]=1;}
           }
     }
      if(vis[i]) cnt++;
      //else cout<<i<<endl;
   }
   printf("%d\n",n-cnt);
   //cout<<n-cnt<<endl;
 }


  }

