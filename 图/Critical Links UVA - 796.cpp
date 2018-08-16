/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
/*genggi***/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<set>
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
const int maxn=11005;
vector<int>edge[maxn];
int low[maxn],dfn[maxn],cut,tot;
//bool iscut[maxn];
int n;
struct node{
 int x,y;
 bool operator<(const node &b)const{
 if(x==b.x) return y<b.y;
 return x<b.x;
 }
};
vector<node>ans;
void init(){
    ans.clear();
    for(int i = 0; i <= n; i++)
        edge[i].clear();
        mem(low);
        mem(dfn);
        //mem(iscut);
       cut = 0;
}
void dfs(int u,int fa){
    low[u] = dfn[u] = ++tot;
    int child=0;//int k=0;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        //if(v==fa&&!k) {k++;continue;}
        if(!dfn[v]){
            dfs(v,u);
            child++;
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]){
               // iscut[u] = true;
                int x=min(u,v);int y=max(u,v);
                ans.push_back(node{x,y});
             }}//attention the position of the {}
        else if(v != fa){
            low[u] = min(low[u],dfn[v]);
        }

//    if(fa<0&&child == 1) iscut[u] = 0;
}
}
int main(){
 // int n; attention redefinition
  while(cin>>n){
    if(n==0) cout<<"0 critical links"<<endl;
  else{
        init();
    for(int i=0;i<n;i++){
        int u;
        cin>>u;
        int m;
        getchar();getchar();
        cin>>m;
        getchar();
        for(int j=0;j<m;j++){
            int v;
            cin>>v;
            edge[u].pb(v);
            edge[v].pb(u);
        }
    }
    for(int i=0;i<n;i++)
       if(!dfn[i]) dfs(i,i);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<" critical links"<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].x<<" - "<<ans[i].y<<endl;;
  }
   cout<<endl;//attention pe
  }

return 0;
}
