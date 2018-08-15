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
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
vector<int>edge[maxn];
ll gcd(ll a,ll b){
         if(a < b){
                   swap(a,b);
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n,m;
  while(cin>>n>>m)
  {
      if(m<n-1||m>n*(n-1)/2){
           cout<<"Impossible"<<endl;continue;
      }
      int k=0;
      //for(int i=0;i<=n;i++)
     // edge[i].clear();
     for(int i=1;i<=n;i++)
     {
         for(int j=i+1;j<=n;j++)
         {
             if(gcd(i,j)==1){
                 edge[i].pb(j);
                k++;
             }
             if(k>=m) break;
         }
         if(k>=m) break;
     }
     if(k<m) cout<<"Impossible"<<endl;
     else {
         cout<<"Possible"<<endl;
         for(int i=1;i<=n;i++)
          for(int j=0;j<edge[i].size();j++)
          {
              cout<<i<<" "<<edge[i][j]<<endl;
          }
     }


  }


  }