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
}a[maxn];
string s[maxn];
ll sl[maxn];
ll sr[maxn];
ll dfs(int a,int b)
{
    if(a==b) return 0;
   if(b==a+1) {
        return max(min(sl[a]-sl[a-1],sr[b]-sr[b-1]),min(sr[a]-sr[a-1],sl[b]-sl[b-1]));
        }
    int mid=(a+b)/2;
    ll a1=dfs(a,mid);
    ll a2=dfs(mid+1,b);
    ll ans=min((sl[mid]-sl[a-1]-a1),(sr[b]-sr[mid]-a2));
    ans=max(ans,min((sr[mid]-sr[a-1]-a1),(sl[b]-sl[mid]-a2)));
    ans+=a1+a2;
 return ans;
}

int main(){
  // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("1002.in","r",stdin);
    freopen("data.out","w",stdout);
   int t;
   //scanf("%d",&t);
   cin>>t;
   while(t--)
   {
       mem(sl,0);
       mem(sr,0);
       int n;
       cin>>n;

       ll ans=0;

       for(int i=1;i<=n;i++)
       {
           a[i].zuo=a[i].you=0;
           cin>>s[i];
           int len=s[i].size();
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
           sl[i]=sl[i-1]+a[i].zuo;
           sr[i]=sr[i-1]+a[i].you;
        //  cout<<sl[i]<<" "<<sl[i]<<endl;

       }

      cout<<ans*2+dfs(1,n)*2<<endl;

   }

 return 0;
  }

/*
5
)))((
))(((
)((
)(((
)))((
**/
