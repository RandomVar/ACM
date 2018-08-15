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
int lowbit(int x){
return x&(-x);
}

void add(int x,int y){
   for(int i=x;i<=n;i+=lowbit(i))
    for(int j=y;j<=n;j+=lowbit(j))
       tree[i][j]--;
}

int sum(int x,int y){
   int ret=0;
   for(int i=x;i>0;i-=lowbit(i))
     for(int j=y;j>0;j-=lowbit(j))
       ret+=tree[i][j];
   return ret;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int a,b,c,m;
  while(cin>>a>>b>>c>>m){
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
          for(int k=1;k<=c;k++)
            cin>>tree[i][j][k];
    int  lat, rat, lbt, rbt, lct, rct, ht;
   for(int i=1;i<=m;i++){
      cin>>lat>>rat>>lbt>>rbt>>lct>>rct>>ht;

   }



  }


  }

