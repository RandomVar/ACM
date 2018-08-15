#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int po[50],pr[50],w[50];
struct node{
 int l,r;
}a[50];
int cmp(node x,node y){
return x.l<y.l;
}
void dfs(int x,int s){
   for(int i=1;i<=x;i++){
    if((s|(1<<i))==0) dfs()
   }
}
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>po[i];
    }
    for(int i=1;i<=n;i++){
        cin>>pr[i];
    }
    int x;cin>>x;
    for(int i=1;i<=x;i++){
        cin>>w[i];
    }
    /*sort(w+1,w+x+1);
    for(int i=1;i<=n;i++){
        a[i].l=po[i]-pr[i];
        a[i].r=po[i]+pr[i];
    }
    int cnt=0;
    sort(a+1,a+1+n,cmp);int k=1;
    for(int i=1;i<=n;i++){
       for(int j=k;j<=x;j++){
         if(a[i].l<w[j]) break;
         if(a[i].r>=w[j]) {cnt++;k=j;}
       }
    }
    cout<<cnt<<endl;*/
  }
  return 0;
}
