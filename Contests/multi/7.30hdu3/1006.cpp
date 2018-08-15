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
const int maxn=100010;
int bit[50];
ll a[maxn];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       mem(bit,0);
       for(int i=1;i<=n;i++)
         cin>>a[i];
         for(int i=1;i<n;i++)
         {
             int u,v;
             cin>>u>>v;
          //   edge[u].pu(v);
           //  edge[v].pb(u);
         }
         int mk=0;
         for(int i=1;i<=n;i++)
         {
             ll t=a[i];
             int k=0;
             while(t)
             {
                bit[k++]+=t%2;
                 t/=2;
             }
             mk=max(k,mk);
         }
         int ans=0;
         for(int i=mk-1;i>=0;i--)
         {
              if(bit[i]%2) {ans=1;break;}
         }
         if(ans==0) cout<<"D"<<endl;
         else cout<<"Q"<<endl;
         
   }

 return 0;
  }

