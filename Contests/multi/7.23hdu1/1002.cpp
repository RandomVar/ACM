/*

问共有n个括号序列，任意排列，子序列括号的匹配数最多为多少

括号序列贪心
法一：
  （ 多于 ） 的放左边，）多于（ 的放右边
   左侧按）少的在前面，右侧按（多的在后面
   右侧相当于左侧反一反

法二：
  匹配数贪心

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
const int maxn=1e5+100;
struct node{
  int zuo,you;
  bool operator<(const node &b)const{
    /*  
    法一：
      if(zuo>=you&&b.zuo<b.you)
        return 1;
      if(zuo<you &&b.zuo >=b.you )
       return 0;
     if(zuo >=you &&b.zuo >=b.you)
        return you < b.you ;
      return zuo >b.zuo ;
      */
    if(min(zuo,b.you)==min(b.zuo,you))
      return zuo>b.zuo;
     return min(zuo,b.you)>min(b.zuo,you);
  }
}a[maxn];
string s[maxn];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   //scanf("%d",&t);
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       //scanf("%d",&n);
       ll ans=0;
        // mem(a,0);
       for(int i=1;i<=n;i++)
       {
           a[i].zuo=a[i].you=0;
           cin>>s[i];
           int len=s[i].size();
           //scanf("%s",s[i]);
           //int len=strlen(s[i]);
           int st=0;
           for(int j=0;j<len;j++)
           {
               if(s[i][j]=='(')
                 st++;
              else if(st>0)
              {
                  st--;
                  ans++;
              }
              else a[i].you++;
           }
           a[i].zuo=st;
           //cout<<a[i].zuo<<" "<<a[i].you<<endl;
       }
       sort(a+1,a+1+n);
       ll zuo=0;
       for(int i=1;i<=n;i++)
       {
           
           ans+=min(zuo,(ll)a[i].you);
            zuo-=min(zuo,(ll)a[i].you);
            zuo+=a[i].zuo;
       }
       cout<<ans*2<<endl;
      //printf("%lld\n",ans*2);
   }

 return 0;
  }

