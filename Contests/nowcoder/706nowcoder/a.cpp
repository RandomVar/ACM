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
struct node{
  int nxt,pre;


}a[maxn];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(cin>>n)
{

    a[0].pre=-1;
    int pre=0;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[pre].nxt=t;
        a[t].pre=pre;
        pre=t;
    }
    a[pre].nxt=n+1;
    a[n+1].pre=pre;
    a[n+1].nxt=n+2;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        string s;int t;
        cin>>s>>t;
        if(s=="FIRST"){
            //a[0].nxt=t;
            if(t==a[0].nxt) continue;
            a[a[t].pre].nxt=a[t].nxt;
            a[a[t].nxt].pre=a[t].pre;

            a[a[0].nxt].pre=t;
            a[t].nxt=a[0].nxt;
            a[0].nxt=t;
            a[t].pre=0;
        }
      else{
            if(t==a[n+1].pre) continue;
          a[a[t].pre].nxt=a[t].nxt;
          a[a[t].nxt].pre=a[t].pre;

          a[a[n+1].pre].nxt=t;
          a[t].pre=a[n+1].pre;
          a[t].nxt=n+1;
          a[n+1].pre=t;

      }
    /*   int j=0;
     while(a[j].nxt!=n+2){
       cout<<a[j].nxt<<" ";
       j=a[j].nxt;
  }
   cout<<endl;*/

    }
    int i=0;
     while(a[i].nxt!=n+1){
        if(a[a[i].nxt].nxt!=n+1)
       cout<<a[i].nxt<<" ";
     else cout<<a[i].nxt;
       i=a[i].nxt;
  }
   cout<<endl;



}

  }

