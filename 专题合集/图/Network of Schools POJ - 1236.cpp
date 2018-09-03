/**
1.弱连通分量的个数：强连通缩点，找入度为0
2.加多少条边变成一个强连通分量 :n为入度为0的点数，m为出度为0的点数：max(n,m)

**/

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<stack>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=110;
vector<int>edge[maxn];
stack<int>st;
int low[maxn],dfn[maxn];
int belong[maxn];
int instack[maxn];
int ru[maxn],chu[maxn];
int tot;int scc;
void tar(int u){
  dfn[u]=low[u]=++tot;
  st.push(u);
  instack[u]=1;
  for(int i=0;i<edge[u].size();i++){
     int v=edge[u][i];
     if(!dfn[v]){
        tar(v);
        if(low[u]>low[v])
            low[u]=low[v];
        }
     else if(instack[v]&&low[u]>dfn[v])
        low[u]=dfn[v];
        }
     if(low[u]==dfn[u]) {
        int v;
         scc++;
         do{
            v=st.top();
            st.pop();
            instack[v]=0;
            belong[v]=scc;
           }while(v!=u);
      }
     }

int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<=n;i++)
     edge[i].clear();
    for(int i=1;i<=n;i++){
        int t;
        while(cin>>t&&t){
            edge[i].pb(t);
        }}
        mem(dfn);
        mem(low);
        mem(instack);
        mem(ru);
        mem(chu);
        while(!st.empty()) st.pop();
        scc=0;
        tot=0;
        for(int i=1;i<=n;i++)
          if(!dfn[i]) tar(i);
        //int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<edge[i].size();j++){
                int t=edge[i][j];
                if(belong[i]!=belong[t]){
                    ru[belong[t]]++;chu[belong[i]]++;
                }
            }
        }
        //cout<<scc<<endl;
        int cnt1=0;int cnt2=0;
        for(int i=1;i<=scc;i++){
         //   cout<<ru[i]<<" "<<chu[i]<<endl;
           if(ru[i]==0) cnt1++;
           if(chu[i]==0) cnt2++;
        }
        if(scc==1) {cout<<1<<endl;cout<<0<<endl;}
        else {cout<<cnt1<<endl;
        cout<<max(cnt1,cnt2)<<endl;}
    }
  return 0;
  }
