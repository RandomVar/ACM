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
int c1[maxn],c2[maxn];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m)
  {
      mem(c1,0);
      mem(c2,0);
     // fill(c1,c1+n+1,0);
     // fill(c2,c2+n+1,0);
      for(int i=1;i<=m;i++)
      {
          int a,b;
          cin>>a>>b;
          c1[a]++;
          c2[b]++;
      }
      int cnt=0;
      for(int i=1;i<=n;i++)
      {
          if(c1[i]==0&&c2[n-i+1]!=-1){
           c1[i]=-1;
           cnt++;
          }
          if(c2[i]==0&&c1[n-i+1]!=-1){
              c2[i]=-1;
              cnt++;
          }
      }
      cout<<cnt<<endl;
  } 

 return 0;
  }

