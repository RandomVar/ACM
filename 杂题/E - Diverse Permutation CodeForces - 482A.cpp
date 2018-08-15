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
int vis[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k){
    a[k]=1;int x=k;
    mem(vis,0);
    vis[1]=1;
    for(int i=k-1;i>=1;i--)
    {
        x--;
        if(a[i+1]-x>0&&!vis[a[i+1]-x])
            a[i]=a[i+1]-x,vis[a[i+1]-x]=1;
        else
          a[i]=x+a[i+1],vis[x+a[i+1]]=1;

    }
    a[k+1]=1+k;
    vis[k+1]=1;
    for(int i=k+2;i<=n;i++){
            if(a[i-1]+1<=n&&!vis[a[i-1]+1])
                 a[i]=a[i-1]+1,vis[a[i-1]+1]=1;
             else a[i]=a[i-1]-1,vis[a[i]]=1;

    }
   for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
   cout<<endl;


  }


}
