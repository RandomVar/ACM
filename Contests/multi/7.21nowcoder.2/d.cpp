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
const int maxn=1e5+100;
int a[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)
        cin>>a[i];
        int cnt=0;
       int pre=0;int ed=0;
       ll ans=0;
       for(int i=1;i<=n;i++)
       {
           if(a[i]>=a[i+1]) 
           {
               if(ed-pre>0){
                cnt++; 
                ans+=ed-pre;
                pre=ed=0;
               }
               continue;
               
               }
           if(pre)
               ed=a[i];
          else pre=a[i];
       }
       cout<<ans<<" "<<cnt<<endl;
   }

 return 0;
  }

