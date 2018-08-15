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
typedef unsigned long long ull;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
template <class T> inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9'))
        c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9')
        ret=ret*10+(c-'0');
    ret*=sgn;
    return 1; }
 
inline void out(ll x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
   }
const int seed=31;
const int maxn=1e6+100;
ull h[maxn];
ull base[maxn];
map<ull,int>mp;
vector<int>vec[maxn];
typedef pair<int,int> P;
void init(){
    base[0]=1;
  for(int i=1;i<maxn;i++)
    base[i]=base[i-1]*seed;
}
ull str_hash(int l,int r){
  return h[r]-h[l-1]*base[r-l+1];
}
int x;
int k,tot;
ull t;
P q[maxn];
 char s[maxn];
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   init();
   while(scanf("%s",s)!=EOF)
   {
    mp.clear();
     int len=strlen(s);
    for(int i=0;i<=len;i++)
       vec[i].clear();
     h[0]=0;
     for(int i=0;i<len;i++)
        h[i+1]=h[i]*seed+s[i]-'a'+1; 
     for(int i=len;i<2*len;i++)
      h[i+1]=h[i]*seed+s[i-len]-'a'+1;
     k=0;
     //priority_queue<P,vector<P>,greater<P> > que;
    tot=0;
     for(int i=1;i<=len;i++)
     {
        t=str_hash(i,i+len);
         if(mp.find(t)==mp.end()){
            
           mp[t]=++k;
           q[tot++]=make_pair(i,k);
         }
          vec[mp[t]].pb(i);
     }
     printf("%d\n",tot);
     for(int j=0;j<tot;j++)
     {
        x=vec[q[j].second].size();
        out(x);
        putchar(' ');
         for(int i=0;i<x;i++)
        {
            out(vec[q[j].second][i]-1);
            putchar(' ');
        }
           printf("\n");
     }
   }
 return 0;
  }