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
//typedef pair<ll,int> P;
map<ll,ll>mp[25];
map<ll,ll>::iterator it;
ll a[30][30];
 int n,m;ll k;
 ll ans;
void dfs(int x,int y,ll sum)
{
    //if(x>n/2||y>m) return;
    if(x+y==(n+m+2)/2){
    
    mp[y][sum]++;
   
    return;
    
    }
  if(x+1<=n)
    dfs(x+1,y,sum^a[x+1][y]);
  if(y+1<=m) 
    dfs(x,y+1,sum^a[x][y+1]);

}

void dfs2(int x,int y,ll sum)
{
   //if(y<0) return;
   if(x+y==(n+m+2)/2)
   {
       ans+=mp[y][sum^a[x][y]^k];
       //cout<<y<<" "<<" "<<(sum^a[x][y]^k)<<" "<<mp[y][sum^a[x][y]^k]<<endl;
      // if(y-1>0)  dfs2(x,y-1,sum^a[x][y-1]);
       return;
   }
   if(x-1>=1)
   dfs2(x-1,y,sum^a[x-1][y]);
 if(y-1>=1)  
 dfs2(x,y-1,sum^a[x][y-1]);

}


int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
    while(cin>>n>>m>>k)
    {
        for(int i=0;i<25;i++)
         mp[i].clear();
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
           cin>>a[i][j];
        ans=0;
        dfs(1,1,a[1][1]);
        dfs2(n,m,a[n][m]);
        cout<<ans<<endl;
    }


 return 0;
  }

