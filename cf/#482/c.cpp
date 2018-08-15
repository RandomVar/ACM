#include<bits/stdc++.h>
using namespace std;
const int maxn=3*1e5+10;
int x,y;
vector<int>edge[maxn];
int noty(int u,int pre){
   if(u==y) return -1;
   if(edge[u].size()==1) return 1;
   int ans=0;
   int e=0;
   for(int i=0;i<edge[u].size();i++){
      int t=edge[u][i];
      if(t==pre) continue;
      e=noty(t,u);
      if(e==-1) return -1;
      else  ans+=e;
   }
   ans+=1;
return ans;
}
int main(){
  int n;
  while(cin>>n>>x>>y){
        for(int i=0;i<maxn;i++)
        edge[i].clear();
      for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
      }
      long long ans=n*(n-1);
      int cnt=0;
     for(int i=0;i<edge[x].size();i++){
         int t=edge[x][i];
         int e=noty(t,x);
        if(e!=-1) cnt+=e;
     }
     //cout<<cnt<<endl;
    if(n==1) cout<<0<<endl;
    else{
    ans-=cnt+1;
    cout<<ans<<endl;
  }}


}
/*
12 1 3
1 2
2 3
2 4
4 5
1 6
1 7
6 8
6 9
7 10
1 11
3 12
*/
