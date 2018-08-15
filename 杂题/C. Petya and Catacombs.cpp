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
int id[maxn],t[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
    for(int i=1;i<=n;i++)
        cin>>t[i];
    map<int,int>mp;
    id[0]=1;
    mp[1]=0;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
      int x=id[t[i]];
      if(mp[x]==t[i]) {
        id[i]=x;
        mp[x]=i;
      }
      else {
        id[i]=++cnt;
        mp[cnt]=i;
      }
    }
    cout<<cnt<<endl;

  }


}
