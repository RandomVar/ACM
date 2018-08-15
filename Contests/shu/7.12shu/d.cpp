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
const int maxn=1e5+100;
int d[maxn];
int n;
typedef pair<int,int>P;
struct node{
	int to;int cost;
};
vector<node>edge[maxn];
int pre[maxn];
int b[maxn];
void dij(){
	memset(d,0x3f,sizeof(d));
	memset(b,-1,sizeof(b));
    d[1]=0;
	priority_queue< P,vector<P>,greater<P> >que;
	que.push(P(0,1));
	while(!que.empty()){
       P a=que.top();que.pop();
       int u=a.second;
       //if(d[u]<a.first) continue; optimize in cf 938d
	   	for(int j=0;j<edge[u].size();j++){
		   node e=edge[u][j];
		 if(d[e.to]>e.cost+d[u]) {
		 d[e.to]=e.cost+d[u];que.push(P(d[e.to],e.to));
         b[e.to]=u;
	   }
	}
}
}
void solve(){
  mem(pre,-1);
  memset(d,0x3f,sizeof(d));
    d[0]=0;
	priority_queue< P,vector<P>,greater<P> >que;
	que.push(P(0,0));
	while(!que.empty()){
       P a=que.top();que.pop();
       int u=a.second;
       //if(d[u]<a.first) continue; optimize in cf 938d
	   	for(int j=0;j<edge[u].size();j++){
		   node e=edge[u][j];
           if(e.to==b[u]) continue;
		 if(d[e.to]>e.cost+d[u]) {
		 d[e.to]=e.cost+d[u];que.push(P(d[e.to],e.to));
         pre[e.to]=u;
	   }
	}
}

  
}
void prin(int u,int pos)
{
 if(u==0) {cout<<pos<<" ";}
if(u==-1) return;
  prin(pre[u],pos+1);    
  cout<<u<<" ";
  if(u==1) cout<<endl;
}

void init(int n)
{
    for(int i=0;i<=n;i++)
    edge[i].clear();
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m)
  {
      init(n);
      for(int i=0;i<m;i++)
      {
          int a,b,d;
          cin>>a>>b>>d;
          edge[a].push_back(node{b,d});
          edge[b].push_back(node{a,d});
      }
      dij();
      solve();
       int u=1;
 /* while(u!=-1)
  {
      cout<<u<<endl;
      u=pre[u];
  }*/
      if(d[1]==inf) cout<<"impossible"<<endl;
      else  prin(1,1);
      //cout<<d[1]<<endl;
  }

return 0;
  }

