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
int d[maxn];
int vis[maxn];
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m){
        int pre=0;
  mem(d,0);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        u=(u+pre)%n+1;v=(v+pre)%n+1;
        int flag=1;
      if(d[v]<d[u]){
            flag=0;
        }
        else{
            d[v]=d[u]+1;
        }
        cout<<flag<<endl;
        pre=flag;
    }


  }


  }

