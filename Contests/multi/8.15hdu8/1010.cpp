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
const int maxn=1e5+100;
int st[maxn];
int ans[maxn];
int daan[maxn];
struct node{
    int x,y,id;
    bool operator<(const node &b)
    {
        return x<b.x;
    }
}q[maxn];
int h[maxn];

void solve(int n)
{
    int top=-1;
    for(int i=n;i>=1;i--)
    {
        while(top!=-1&&h[i]>=h[st[top]])
          top--;
        st[++top]=i;
        ans[i]=top+1;
    }
}
int top2;
typedef pair<int,int> P;
P st2[maxn];
int n;
void solvest(int id)
{
    while(top2>0&&h[id]>=st2[top2].fir)
     top2--;
     st2[++top2].fir=h[id];
     st2[top2].sec=id;
}
int getid(int l,int r,int y)
{
   
    while(l<=r)
    {
        int mid=(l+r)/2;
       // cout<<"!"<<mid<<endl;
        if(st2[mid].fir<=y)
          r=mid-1;
        else l=mid+1;
    }
    return r;
}
int queryst(int x)
{

    int p=getid(0,top2,x);

    return st2[p].sec;

}
int c[maxn];
int cnt[maxn];
void init()
{
    c[0]=0;
    cnt[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i]>c[i-1])
          c[i]=h[i],cnt[i]=cnt[i-1]+1;
          else c[i]=c[i-1],cnt[i]=cnt[i-1];
     }
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  while(t--)
  {
     int m;
      scanf("%d%d",&n,&m);
     // v.clear();
      for(int i=1;i<=n;i++)
       scanf("%d",&h[i]);//v.pb(h[i]);
     //  sort(v.begin(),v.end());
      // v.erase(unique(v.begin(),v.end()),v.end());
    
       solve(n);
       ans[n+1]=0;
      // for(int i=1;i<=n;i++)
      //  cout<<i<<" "<<ans[i]<<endl;
       for(int i=1;i<=m;i++)
       {
           scanf("%d%d",&q[i].x,&q[i].y);
           q[i].id=i;
       }
      init();
       sort(q+1,q+1+m);
       int pre=n;
       top2=0;
       st2[0].fir=inf;
       st2[0].sec=n+1;
    for(int i=m;i>=1;i--)
    {
      
       for(int j=pre;j>q[i].x;j--)
       {
           solvest(j);
       }
       pre=q[i].x;
  
       //cout<<q[i].id<<" "<<w<<endl;
       if(q[i].y>c[q[i].x-1])
       {
            int w=queryst(q[i].y);
           // cout<<q[i].id<<" "<<w<<endl;
         daan[q[i].id]=ans[w]+cnt[q[i].x-1]+1;
       }
      else
        {
            int k=queryst(c[q[i].x-1]);
          //  cout<<q[i].id<<" "<<k<<endl;
             daan[q[i].id]=ans[k]+cnt[q[i].x-1];
        }
    }

    for(int i=1;i<=m;i++)
     printf("%d\n",daan[i]);

  }
 return 0;
  }

