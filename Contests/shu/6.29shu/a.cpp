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
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int x,y;
   while(cin>>x>>y){
        ll a1=0;ll a2=0;
     for(int i=1;i<=x;i++){
         int t;
         cin>>t;
         a1=a1*y+t;
     }
     int c,d;
     cin>>c>>d;
     for(int i=1;i<=c;i++){
        int t;
        cin>>t;
        a2=a2*d+t;
     }
     if(a1<a2) cout<<"<"<<endl;
     else if(a1==a2) cout<<"="<<endl;
     else cout<<">"<<endl;

   }


}
