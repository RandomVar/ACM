#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
vector<int>edge[maxn];
int deg[maxn];
int biao[maxn];
int k;
int dfn[maxn];
void dfs(int x){
  for(int i=0;i<edge[x].size();i++){
     int t=edge[x][i];
     dfn[++k]=t;;
     dfs(t);
  }
}
int main(){
  int n;
  while(cin>>n){
        memset(deg,0,sizeof(deg));
       memset(biao,0,sizeof(biao));
       for(int i=1;i<=n;i++)
        edge[i].clear();
    for(int i=1;i<=n;i++){
            int t;
            cin>>t;
       if(t) {edge[i].push_back(t);
              edge[t].push_back(i);
              deg[i]++;deg[t]++;
              }
    }
    dfn[1]=1;
    k=1;
    dfs(1);
    for(int i=n;i>=1;i--){
        int t=dfn[i];
        if(deg[t]>=0&&deg[t]%2==0){
            deg[t]=-1;
            for(int i=0;i<edge[t].size();i++){
                int x=edge[t][i];
                deg[x]--;
                if(deg[x]>=0&&deg[x]%i==0){

                }
            }
        }
    }
}

}
