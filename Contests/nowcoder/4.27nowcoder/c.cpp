#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=110;
struct node{
  int x,y;
}a[maxn];
int p[maxn];
int cnt[maxn];
int n;
void init(){
  for(int i=1;i<=n;i++)
    p[i]=i;/*根节点初始化为自己*/
}
int find(int x){
 return x==p[x]?x:find(p[x]);
}
void unin(int x,int y){
  x=find(x);y=find(y);
  if(x!=y) p[x]=y;
}

int main(){

  while(cin>>n){
    //int k=0
    init();
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        int flag=0;
        for(int j=0;j<i;j++){
            if(a[i].x==a[j].x||a[i].y==a[j].y)
                unin(i,j);
    }
  }
  int ans=0;
  memset(cnt,0,sizeof(cnt));
     for(int i=0;i<n;i++){
       int t=find(i);
        if(cnt[t]==0) {cnt[t]=1;ans++;}
     }
     cout<<ans-1<<endl;
}
return 0;}
