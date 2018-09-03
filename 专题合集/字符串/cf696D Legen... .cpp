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
const int maxnode=210;
ll val[maxnode];
struct Mat{  
    int n;  
    ll maze[maxnode][maxnode];  

    void init(int N){  
        n = N;  
        mem(maze,-0x3f);  
    } 

    Mat operator + (Mat &rhs){  
        Mat m;  
        m.init(n);  
        for(int i=0;i<n;i++){  
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    m.maze[i][j]=max(m.maze[i][j],maze[i][k]+rhs.maze[k][j]);
                }
            }  
        }  
        return m;
    }  
};  

Mat qpow(Mat A,ll n){
    if(n==1) return A;
    Mat ans=A;
    n--;
    while(n){
        if(n&1) ans=ans+A;
        A=A+A;
        n>>=1;
    }
    return ans;
}

struct trie{
   int next[maxnode][26],fail[maxnode];ll ed[maxnode];//attention
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
   }

   void inser(char* buf,int id){
     int len=strlen(buf);
     int now=root;
     for(int i=0;i<len;i++){
         if(next[now][buf[i]-'a']==-1)
             next[now][buf[i]-'a']=newnode();
         now=next[now][buf[i]-'a'];
      }
     ed[now]+=val[id];
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
        }}
        while(!que.empty()){
            int now=que.front();
            que.pop();
            ed[now]+=ed[fail[now]];
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
  Mat dp;
  ll query(ll l)
  {
     dp.init(cnt);
     for(int i=0;i<cnt;i++)
       for(int j=0;j<26;j++)
       {
           dp.maze[i][next[i][j]]=ed[next[i][j]];
       }
      dp=qpow(dp,l);
      ll ans=0;
      for(int i=0;i<cnt;i++)
        ans=max(ans,dp.maze[0][i]);
    return ans;
  }
};
char buf[205];
trie ac;
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;ll l;
    while(scanf("%d%lld",&n,&l)==2)
    {
        for(int i=1;i<=n;i++)
         scanf("%lld",&val[i]);
         ac.init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",buf);ac.inser(buf,i);
        }
        ac.build();
        printf("%lld\n",ac.query(l));
    }

 return 0;
  }
