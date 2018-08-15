/*
利用线段树将点与区间连线，再拓扑排序
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
typedef pair<ll,int> P;
int n;
const int maxn=2e5+100;
int id[maxn<<2];
int pos[maxn];
int f[maxn];
int deg[maxn<<2];
vector<int>edge[maxn<<2];
ll a[maxn];
void init(int n)
{
    for(int i=0;i<(n<<2)+5;i++)
      edge[i].clear();
     memset(deg, 0, sizeof(int) * (n << 2 | 5));

}
int judge(int s,int t)
{
   if(s<=t)
   {
      if(f[t]-f[s-1]==0) return 1;
   }
   else if(f[n]-f[s-1]==0&&f[t]==0)
    return 1;
    return 0;
}
void add(int u,int v)
{
    edge[u].pb(v);
    deg[v]++;
}
void addedge(int l,int r,int L,int R,int p,int rt)
{
    if(l>=L&&r<=R)
    {
        add(rt,p);
        return;
    }
    int mid=(l+r)/2;
   if(L<=mid) addedge(l,mid,L,R,p,rt*2);
   if(R>mid) addedge(mid+1,r,L,R,p,rt*2+1);

}
void build(int l,int r,int rt)
{
    id[rt]=-1;
    if(l==r)
    {
        pos[l]=rt;
        id[rt]=l;
        return;
    }
    int mid=(l+r)/2;
    add(rt*2,rt);
    add(rt*2+1,rt);
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}
void  top()
{
    priority_queue<P,vector<P>,greater<P> >que;
   for(int i=1;i<=n;i++)
   {
       if(deg[pos[i]]==0) que.push(make_pair(a[i],pos[i]));
   }
   vector<ll>ans;
   while(!que.empty())
   {
       P e=que.top();
       que.pop();
       if(e.first!=-1) ans.pb(e.first);
     for(int i=0;i<edge[e.second].size();i++)
     {
         int u=edge[e.sec][i];
         deg[u]--;
         //cout<<id[u]<<" ";
         if(deg[u]==0)
           que.push(make_pair(id[u]==-1?-1:a[id[u]],u));
     }
    // cout<<endl;
   }
  // cout<<ans.size()<<endl;
   if(ans.size()!=n-f[n])
    {cout<<-1<<endl;return;}

  for(int i=0;i<ans.size();i++)
   printf("%lld ",ans[i]);
  printf("\n");
}

int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
      
       scanf("%d",&n);
       init(n);
       for(int i=1;i<=n;i++)
       {
           scanf("%lld",&a[i]);
               if(i)
                 f[i]=f[i-1]+(a[i]==-1);
               else 
                 f[i]=(a[i]==-1);
       }
    
       int flag=0;
       for(int i=1;i<=n;i++)
       {
           if(a[i]!=-1&&!judge(a[i]%n+1,i))
             {flag=1;break;}
       }
       if(flag) {cout<<-1<<endl;continue;}
       build(1,n,1);
       for(int i=1;i<=n;i++)
       {
           if(a[i]!=-1)
           {
               int s=a[i]%n+1;int t=i;
               if(s==t) continue;
               if(s<t)
                 addedge(1,n,s,t-1,pos[i],1);
               else{
                 if(t>1)  addedge(1,n,1,t-1,pos[i],1);
                   addedge(1,n,s,n,pos[i],1);
               }
           }
       }
       top();
   }

 return 0;
  }

