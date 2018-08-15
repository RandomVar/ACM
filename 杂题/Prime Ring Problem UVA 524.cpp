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
int isprime[50];
int vis[20];
int nn;
int a[40];
void init()
{
      for(int i=2;i<50;i++)
        isprime[i]=1;
    //isprime[2]=1;
    for(int i=2;i<50;i++)
    {
      if(isprime[i])
        for(int j=2;j*i<50;j++)
               isprime[j*i]=0;
    }

}

void dfs(int x,int pos){
    
    if(pos==nn&&isprime[x+1]) 
    {
      for(int i=1;i<pos;i++)
         printf("%d ",a[i]);
        //cout<<a[i]<<" ";
        printf("%d\n",x);
    //    cout<<x<<endl;
      return;
    }

    for(int i=1;i<=nn;i++)
    {
        if(!vis[i]&&isprime[x+i])
        {
       //     cout<<i<<pos+1<<endl;
            vis[i]=1;
            a[pos+1]=i;
           // pre[i]=x;
           dfs(i,pos+1);
           vis[i]=0;       
        }
    }
}
int main(){
 // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 // int n;
  init();
  int cas=0;
  while(scanf("%d",&nn)==1&&nn)
  {
      mem(vis,0);
      vis[1]=1;
      a[1]=1;
      if(cas) printf("\n");
      printf("Case %d:\n",++cas);
      // cout<<"Case "<<++cas<<":"<<endl;
      dfs(1,1);
      
    //  cout<<endl; 
  }
 

  }

