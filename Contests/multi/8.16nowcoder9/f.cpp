/*
 求四个模式串的前缀与字符串的每一个后缀的匹配中，模式串前缀到结尾的最短距离。字符串可退格。
 
 AC自动机 bfs预处理出最短距离
 退格操作只要用栈模拟即可
*/

#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxnode=1e5+100;

struct trie{
   int next[maxnode][26],fail[maxnode],ed[maxnode];//attention
   int st[maxnode];
   int d[maxnode];
   vector<int>edge[maxnode];
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
      for(int i=0;i<maxnode;i++)
       edge[i].clear();
      //mem(dis,0x3f);
   }

   void inser(char* buf){
     int len=strlen(buf);
     int now=root;
     for(int i=0;i<len;i++)
      {
         if(next[now][buf[i]-'a']==-1)
             next[now][buf[i]-'a']=newnode();
         now=next[now][buf[i]-'a'];
       //  dis[now]=min(dis[now],len-i-1);
      }
     ed[now]=1;
   }

   void build(){
     queue<int>que;
     fail[root]=root;
    
     for(int i=0;i<26;i++){
        if(next[root][i]==-1)
             next[root][i]=root;
        else{
            fail[next[root][i]]=root;
            que.push(next[root][i]);
        }
        }
        while(!que.empty()){
            int now=que.front();
            que.pop();
            ed[now]|=ed[fail[now]];
            for(int i=0;i<26;i++){
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
        }
     }
  
  void bfs()
  {
         mem(d,-1);
      queue<int>que;
      for(int i=0;i<cnt;i++)
        for(int j=0;j<26;j++)
          edge[next[i][j]].pb(i);
        for(int i=0;i<cnt;i++)
           if(ed[i]) d[i]=0,que.push(i);
     
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=0;i<edge[u].size();i++)
            {
                int v=edge[u][i];
                if(d[v]!=-1) continue;
                d[v]=d[u]+1;
                que.push(v);
            }
        }
  }

  void query(char* buf){
    int len=strlen(buf);
    int now=root;
    int top=-1;
    printf("%d\n",d[root]);
    for(int i=0;i<len;i++){
      if(buf[i]=='-')
      {
         if(top>=0) top--;
         if(top>=0) now=st[top];
         else now=root;
         printf("%d\n",d[now]);
      }
      else{
          now=next[now][buf[i]-'a'];
          st[++top]=now;
          printf("%d\n",d[now]);
      }
    }
  }
};
char buf[maxnode];
trie ac;
int main(){
 // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
    ac.init();
    for(int i=0;i<n;i++)
        scanf("%s",buf),ac.inser(buf);
        //cin>>buf,ac.inser(buf);
    ac.build();
    ac.bfs();
    scanf("%s",buf);
    ac.query(buf);
    //cin>>buf;
    // cout<<ac.query(buf)<<endl;
    }

return 0;
}

