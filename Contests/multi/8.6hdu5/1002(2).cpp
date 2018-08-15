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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/


char s[20];

ll k;int len;
int vis[10];
int cc[20];


int check()
{
    mem(vis,0);
    int cnt=0;
    
    for(int i=0;i<len;i++)
    {
        if(vis[i]) continue;
        int x=0;
        while(!vis[i])
        {
            x++;
            vis[i]=1;
            i=cc[i];
        }
          cnt+=x-1;
        if(cnt>k) return 0;
    }
    return cnt<=k;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
      
       scanf("%s%lld",s,&k);
       len=strlen(s);
  
     ll a1=0;ll a2=1e9+100;
      for(int i=0;i<len;i++)
        cc[i]=i;
      do{
        
          if(s[cc[0]]!='0'&&check())
               {
                   ll ans=0;
                   for(int i=0;i<len;i++)
                     ans=ans*10+s[cc[i]]-'0';
                    if(ans>a1)
                      a1=ans;
                    if(ans<a2)
                     a2=ans;
               }
            
      }while(next_permutation(cc,cc+len));
      printf("%lld %lld\n",a2,a1);
   }
}