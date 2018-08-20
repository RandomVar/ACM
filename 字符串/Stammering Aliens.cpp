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
typedef unsigned long long ull;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=4e4+100;
const int seed=31;
int m;
char s[maxn];
ull base[maxn];
ull h[maxn];
//pair<ull,int> aa[maxn];
struct node{
    ull fir;int sec;
    bool operator<(const node &b)const
    {
        if(fir==b.fir) return sec<b.sec;
        return fir<b.fir;
    }
}aa[maxn];
void init()
{
  base[0]=1;
  for(int i=1;i<maxn;i++)
    base[i]=base[i-1]*seed;
}
ull str_hash(int l,int r){
  return h[r]-h[l]*base[r-l];
}
void Hash(char *s,int len)
 {
     h[0]=0;
   for(int i=0;i<len;i++)
      h[i+1]=h[i]*seed+s[i]-'a'+1; 
  }
int check(int mid,int len)
{
    for(int i=0;i<=len-mid;i++)
    {
        aa[i].fir=str_hash(i,i+mid);
        aa[i].sec=i;
    }
    sort(aa,aa+len-mid+1);
    int cnt=1;
    ull pre=aa[0].fir;
    int ans=-1;
    if(cnt>=m) ans=max(ans,aa[0].sec);
    for(int i=1;i<=len-mid;i++)
    {
        if(aa[i].fir!=pre) cnt=1,pre=aa[i].fir;
        else cnt++;
        if(cnt>=m) ans=max(ans,aa[i].sec);
    }
    return ans;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  init();
  while(scanf("%d",&m)==1&&m)
  {
      scanf("%s",s);
      int len=strlen(s);
       Hash(s,len);
      int l=1,r=len;
      int ans=-1;
      int pos=0;
      while(l<=r)
      {
          int mid=(l+r)/2;

          int x=check(mid,len);
        // cout<<"*"<<mid<<" "<<x<<endl;
          if(x!=-1)
            l=mid+1,ans=mid,pos=x;
          else r=mid-1;
         
      }
      if(ans==-1) printf("none\n");
      else printf("%d %d\n",ans,pos);
  }

 return 0;
  }