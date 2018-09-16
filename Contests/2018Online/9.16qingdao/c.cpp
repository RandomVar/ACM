#include<bits/stdc++.h>
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

namespace IO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read

    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};


const int maxn=1e4+10;
const int mod=256;
struct node{
  int op;int v,k;
}a[maxn];
int vis[maxn][260];
int check(int n)
{
  // mem(vis,0);
  for(int i=1;i<=n+1;i++)
    memset(vis[i],0,sizeof(vis[i]));
  int i=1;int now=0;
  vis[1][0]=1;
  while(i<=n)
  {
    if(a[i].op==1)
    {
      // vis[i][now]=1;
      now=(now+a[i].v)%mod;
      if(vis[i+1][now]) return 0;
      vis[i+1][now]=1;
      i++;
      continue;
    }
    if(a[i].op==2)
    {
      if(now==a[i].v) i=a[i].k;
      else i++;
      if(vis[i][now]) return 0;
      vis[i][now]=1;
      continue;
    }
    if(a[i].op==3)
    {
      if(now!=a[i].v) i=a[i].k;
        else i++;
        if(vis[i][now]) return 0;
        vis[i][now]=1;
      continue;
     }
     if(a[i].op==4)
     {
       if(now<a[i].v) i=a[i].k;
       else i++;
       if(vis[i][now]) return 0;
       vis[i][now]=1;
       continue;
     }
     if(a[i].op==5)
     {
       if(now>a[i].v) i=a[i].k;
       else i++;
       if(vis[i][now]) return 0;
       vis[i][now]=1;
       continue;
      }
  }
  return 1;
}
char s[10];
int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   IO::read(t);
  //  scanf("%d",&t);
   while(t--)
   {
     int n;
     IO::read(n);
    //  scanf("%d",&n);
     for(int i=1;i<=n;i++)
     {
       IO::read(s);
      //  scanf("%s",s);
       if(strcmp(s,"add")==0)
       {
         a[i].op=1;
         IO::read(a[i].v);
        //  scanf("%d",&a[i].v);
       }
       else
       {
         IO::read(a[i].v);
         IO::read(a[i].k);
        // scanf("%d%d",&a[i].v,&a[i].k);
        if(strcmp(s,"beq")==0)
         a[i].op=2;
         else if(strcmp(s,"bne")==0)
          a[i].op=3;
        else if(strcmp(s,"blt")==0)
         a[i].op=4;
         else if(strcmp(s,"bgt")==0)
          a[i].op=5;
      }
     }
     int now=0;
     if(check(n))
     IO::println("Yes");
    //  printf("Yes\n");
     else
     IO::println("No");
    //  printf("No\n");
   }
 return 0;
  }
