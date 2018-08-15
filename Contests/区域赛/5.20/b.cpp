#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int a[maxn];
int main(){
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      for(int i=0;i<=n;i++)
      {
        cin>>a[i].x>>a[i].y>>a[i].r>>a[i].c;
      }
      for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
          if(a[j].x<=a[i].x+a[i].r&&a[j].x>=a[i].x-a[i].r&&a[j].y<=a[i].y+a[i].r&&a[j].y>=a[i].y-a[i].r){
              vec[i].push_back(j);
              a[i].sum+=a[j].c;
        }
      }
      for(int i=0;i<=n;i++)
      {
        sort(a+i,a+n+1);
      }


  }


}
