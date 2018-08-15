#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<sstream>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=105;
vector<int>edge[maxn];
int low[maxn],dfn[maxn],cut,tot;
bool iscut[maxn];
int n;
void init(){
    for(int i = 1; i <= n; i++)
        edge[i].clear();
        mem(low);
        mem(dfn);
        mem(iscut);
       cut = 0;
}
void dfs(int u,int fa){
    low[u] = dfn[u] = ++tot;
    int child=0;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(!dfn[v]){
            dfs(v,u);
            child++;
            low[u] = min(low[u],low[v]);
            if(low[v] >= dfn[u])
                iscut[u] = true;
        }
        else if(v != fa){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(fa<0&&child == 1) iscut[u] = 0;
}
int main(){
  //int n;
  while(cin>>n&&n){
       // cout<<n<<"*"<<endl;
    string s;
  getchar();
  init();
    while(getline(cin,s)){
    //cout<<s<<endl;
    stringstream ss(s);
    int u;
    ss>>u;
    if(u==0) break;

    int t;
    while(ss>>t){
        edge[u].pb(t);
        edge[t].pb(u);
    }
    //getchar();
    }
    int cnt=0;
   dfs(1,-1);
    for(int i=1;i<=n;i++){
        if(iscut[i]) {cnt++;}
    }
    cout<<cnt<<endl;
  }
return 0;
}
