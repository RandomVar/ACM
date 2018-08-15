#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
struct node{
    int val;
    int pre;
    int nex;
}a[maxn];
int ss[maxn];
int tt[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
      int n,q;
      while(scanf("%d%d",&n,&q)==2)
      {
          int k=0;
          for(int i=1;i<=q;i++)
          {
              int op;
             scanf("%d",&op);
             if(op==1)
             {
                 scanf("%d%d%d",&u,&w,&val);
                 if(w==1)
                 {
                     tt[u].nex=++k;
                     a[k].pre=tt[u];
                     tt[u]=k;
                     a[k].val=val;    
                 }
                 else{
                    ss[u]
                 }

                 //uu ww valval 
             }
          }
      }
      //tR6ZzZ3MHH


 return 0;
  }
