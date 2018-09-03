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
const int INF=0x3f3f3f3f;
//const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int MAXN = 1001000;
vector<int>G[MAXN];
int uN;
int Mx[MAXN],My[MAXN];
int dx[MAXN],dy[MAXN];
int dis;
bool used[MAXN];
bool SearchP() {
 queue<int>Q;
  dis = INF;
  memset(dx,-1,sizeof(dx));
  memset(dy,-1,sizeof(dy));
  for(int i = 0 ; i < uN; i++)
     if(Mx[i] == -1)  {
         Q.push(i);
        dx[i] = 0;  }
      while(!Q.empty()) {
          int u = Q.front();
          Q.pop();
      if(dx[u] > dis)
        break;
      int sz = G[u].size();
      for(int i = 0;i < sz;i++) {
            int v = G[u][i];
       if(dy[v] == -1)   {
            dy[v] = dx[u] + 1;
     if(My[v] == -1)dis = dy[v];
     else    {
        dx[My[v]] = dy[v] + 1;
        Q.push(My[v]);
         } } } }

return dis != INF;
}

 bool DFS(int u) {
     int sz = G[u].size();
     for(int i = 0;i < sz;i++) {
            int v = G[u][i];
       if(!used[v] && dy[v] == dx[u] + 1)  {
            used[v] = true;
       if(My[v] != -1 && dy[v] == dis)
          continue;
        if(My[v] == -1 || DFS(My[v]))  {
                My[v] = u;
               Mx[u] = v;
      return true;
      }   } }
return false; }


int MaxMatch() {
    int res = 0;
    memset(Mx,-1,sizeof(Mx));
     memset(My,-1,sizeof(My));
     while(SearchP()) {
        memset(used,false,sizeof(used));
        for(int i = 0;i < uN;i++)
          if(Mx[i] == -1 && DFS(i))
            res++;
           else return res;
          }
return res;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  uN=1000000;
  while(cin>>n){
     for(int i=1;i<=n;i++){
          int x,y;
          cin>>x>>y;
          G[x-1].pb(i);
          G[y-1].pb(i);
     }
     cout<<MaxMatch()<<endl;

  }


}
