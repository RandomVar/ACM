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
const int maxn=1e6+100;

struct trie{
   int next[maxn][26],ed[maxn];
   int d[maxn];
   vector<int>edge[maxn];
   int root,cnt;
   int newnode(){
     for(int i=0;i<26;i++)
       next[cnt][i]=-1;
      ed[cnt++]=0;
    return cnt-1;
   }
   void init(){
     cnt=0;
     root=newnode();
     for(int i=0;i<maxn;i++)
      edge[i].clear();
   }
   void inser(char *buf){
      int len=strlen(buf);
      int now=root;
     for(int i=0;i<len;i++)
     {
       int t=buf[i]-'a';
       if(next[now][t]==-1)
         next[now][t]=newnode();
        now=next[now][t];
     }
     ed[now]++;
     int v=root;
     for(int i=0;i<len;i++)
     {
       int t=buf[i]-'a';
       v=next[v][t];
       if(edge[v].empty()&&!ed[v])
       {
         edge[v].pb(now);
       }
     }
   }
   void dfs(int u)
   {
     for(int i=0;i<26;i++)
     {
       if(next[u][i]!=-1){
           edge[next[u][i]].pb(u);
           edge[u].pb(next[u][i]);
           dfs(next[u][i]);
       }
     }
   }
   void bfs()
   {
     queue<int>que;
     que.push(root);
     mem(d,-1);
     d[root]=0;
     while(!que.empty())
     {
       int u=que.front();
       que.pop();
       for(int i=0;i<edge[u].size();i++)
       {
         int v=edge[u][i];
         if(d[v]!=-1)
           continue;
          d[v]=d[u]+1;
          que.push(v);
       }
            }
   }
   int solve(char *buf)
   {
     int now=root;
     int ans=0;
     int len=strlen(buf);
     for(int i=0;i<len;i++)
     {
        int t=buf[i]-'a';
        if(next[now][t]==-1)
          break;
        now=next[now][t];
        ans++;
     }
     return d[now]+len-ans; 
   }
 
};
trie tr;
char s[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m)
  {
  tr.init();
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      tr.inser(s);
    }
    tr.dfs(tr.root);
     tr.bfs();
     for(int i=0;i<m;i++)
     {
       cin>>s;
       cout<<tr.solve(s)<<endl;
     }
    

  }


  }

