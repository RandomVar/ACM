#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
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

/****AC自动机 HUD-2222****/
/*以now节点结尾的后缀 与 root-fail[now]所表示的字符串 相同*/
const int maxn=20;
const int maxnode=20*10;
const int MOD= 100000;
typedef vector<ll> vec;
typedef vector<vec> mat;
int id(char c)
{
    if(c=='A') return 0;
    if(c=='C') return 1;
    if(c=='T') return 2;
    if(c=='G') return 3; 
}
mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
	  for(int k=0;k<B.size();k++)
	    for(int j=0;j<B[0].size();j++)
	      C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
	return C;
}
//A^n
mat pow(mat A,ll n){
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++)
	  B[i][i]=1;
	while(n>0){
		if(n&1) B=mul(B,A);
		A=mul(A,A);
		n>>=1;
	}
	return B;
}
const int NUMA=4;
struct trie{
    
   int next[maxnode][NUMA],fail[maxnode],ed[maxnode];//attention
   int root,cnt;
   int newnode(){
      for(int i=0;i<NUMA;i++)
        next[cnt][i]=-1;
      ed[cnt++]=0;
      return cnt-1;
   }
   
   void init(){
      cnt=0;
      root=newnode();
   }

   void inser(char* buf){
     int len=strlen(buf);
     int now=root;
     for(int i=0;i<len;i++){
         int x=id(buf[i]);
         if(next[now][x]==-1)
             next[now][x]=newnode();
         now=next[now][x];
     }
     ed[now]=1;
   }

   void build(){
     queue<int>que;
     fail[root]=root;
     for(int i=0;i<NUMA;i++){
        if(next[root][i]==-1)
             next[root][i]=root;
        else{
            fail[next[root][i]]=root;
            que.push(next[root][i]);
        }}
        while(!que.empty()){
            int now=que.front();
            ed[now]|=ed[fail[now]];
            que.pop();
            for(int i=0;i<NUMA;i++){
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
        }
     }

  ll solve(ll n)
  {
      mat A(cnt,vec(cnt));
      for(int i=0;i<cnt;i++)
       for(int j=0;j<cnt;j++)
        A[i][j]=0;
    for(int i=0;i<cnt;i++)
       for(int j=0;j<4;j++)
        if(!ed[i]&&!ed[next[i][j]]) A[i][next[i][j]]++;
     A=pow(A,n);
    //   for(int i=0;i<cnt;i++)
    //   for(int j=0;j<cnt;j++)
    //    cout<<A[i][j]<<" ";
    //    cout<<endl;

    ll ans=0;
    for(int i=0;i<cnt;i++)
     ans=(ans+A[0][i])%MOD;
   return ans;
  }
};
trie ac;
char s[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   ll n;
   while(scanf("%d%lld",&m,&n)==2)
   {
       ac.init();
       for(int i=1;i<=m;i++)
         scanf("%s",s),ac.inser(s);
       ac.build();
       printf("%lld\n",ac.solve(n));
       
   }  
 return 0;
  }
