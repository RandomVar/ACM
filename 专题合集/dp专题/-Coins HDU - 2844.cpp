#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int vis[100010];
int a[110];
int c[110];
int sum[100010];
int main(){
  int n,m;
  while(cin>>n>>m){
    if(n==0&&m==0)break;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(int i=0;i<n;i++){
      memset(sum,0,sizeof(sum));
     for(int s=a[i];s<=m;s++){
        if(sum[s-a[i]]<c[i]&&vis[s-a[i]]&&!vis[s]) {vis[s]=1;sum[s]=sum[s-a[i]]+1;}
    }
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(vis[i]) cnt++;
    cout<<cnt<<endl;
  }
}
