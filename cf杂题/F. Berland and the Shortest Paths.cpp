/*
http://codeforces.com/contest/1005/problem/F
*/
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
const int maxn=2*1e5+100;
vector<int>edge[maxn];
vector<int>to[maxn];
int st[maxn];
int n,k;
typedef pair<int,int> P;
map<P,int>id;
//typedef  char[ String;
vector<string>daan;
void init(int n)
{
    for(int i=0;i<=n;i++)
      {edge[i].clear();to[i].clear();}
    mem(st,0);
    id.clear(); 
    daan.clear();
}

void bfs()
{
   st[1]=1;
   queue<int>que;
   que.push(1);
   while(!que.empty())
   {
         int t=que.front();
         que.pop();
         for(int i=0;i<edge[t].size();i++)
         {
             int x=edge[t][i];
             //if(st[x]) continue;
            if(!st[x]){
             st[x]=st[t]+1;
             to[x].pb(t);
             que.push(x);
            }
            else if(st[x]==st[t]+1)
              to[x].pb(t);
            //mm=st[x];
         }
   }
}

void prin(int x,char *ans)
{
    if(daan.size()>=k) return;
    //ans[x]='1';
    if(x==n+1) {
       // cout<<ans<<endl;
        daan.push_back(ans);
        return;
    }
    for(int i=0;i<to[x].size();i++){
       int u=x;int v=to[x][i];
       if(u>v) swap(u,v);
       int t=id[make_pair(u,v)];
       ans[t]='1';
       prin(x+1,ans);
       ans[t]='0';
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   while(cin>>n>>m>>k)
   {
       init(n);
       for(int i=0;i<m;i++)
       {
           int u,v;
           cin>>u>>v;
           edge[u].push_back(v);
           edge[v].push_back(u);
           if(u>v) swap(u,v);
           id[make_pair(u,v)]=i;
       }
       bfs();

       char ans[maxn];
       for(int i=0;i<m;i++)
        ans[i]='0';
        ans[m]='\0';
       //cout<<ans<<endl;
       prin(2,ans);
       int t=daan.size();
       t=min(t,k);
       cout<<t<<endl;
       for(int i=0;i<t;i++)
          //printf("%s\n",daan[i]);
          cout<<daan[i]<<endl;
   }

 return 0;
  }

