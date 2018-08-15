/*
点到点，点到区间，区间到点建边

建两棵树，给节点标号，将点连到线段树的对应点
建两棵树使得每次必须走到实际的点，而不是线段树上的节点

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
typedef pair<ll,int>P;
struct node{
   int to;ll cost;
};
vector<node>edge[maxn<<4];
int id1[maxn<<4];
int id2[maxn<<4];
int vis[maxn<<4];
ll d[maxn<<4];
int tot;
void init()
{

}
void add(int u,int v,int w)
{
    edge[u].push_back(node{v,w});
}

void build1(int l,int r,int rt)
{
    id1[rt]=++tot;
    for(int i=l;i<=r;i++)
     add(id1[rt],i,0);
    if(l==r)
        return;
    int mid=(l+r)/2;
   
    build1(l,mid,rt*2);
    build1(mid+1,r,rt*2+1);
}
void build2(int l,int r,int rt)
{
    id2[rt]=++tot;
    for(int i=l;i<=r;i++)
      add(i,id2[rt],0);
    if(l==r)
        return;
    int mid=(l+r)/2;

    build2(l,mid,rt*2);
    build2(mid+1,r,rt*2+1);
}

void addedge1(int l,int r,int L,int R,int p,int w,int rt,int flag)
{
    
    if(l>=L&&r<=R)
    {
        if(flag==1)
         add(p,id1[rt],w);
        else add(id2[rt],p,w);
        return;
    }
    int mid=(l+r)/2;
    if(L<=mid)
     addedge1(l,mid,L,R,p,w,rt*2,flag);
     if(R>mid)
      addedge1(mid+1,r,L,R,p,w,rt*2+1,flag);
}

void dij(int s)
{
    priority_queue<P,vector<P>,greater<P> >que;
    que.push(make_pair(0,s));
    mem(d,0x3f);
    mem(vis,0);
    d[s]=0;
   while(!que.empty())
   {
       P e=que.top();
       que.pop();
       if(vis[e.sec]) continue;
       vis[e.sec]=1;
       for(int i=0;i<edge[e.sec].size();i++)
       {
           node u=edge[e.sec][i];
           if(!vis[u.to]&&d[u.to]>d[e.sec]+u.cost)
             {
                 d[u.to]=d[e.sec]+u.cost;
               //  cout<<u.to<<" "<<d[u.to]<<endl;
                 que.push(make_pair(d[u.to],u.to));
             }
       }
   }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q,s;
    while(scanf("%d%d%d",&n,&q,&s)==3)
    {
         tot=n;
        build1(1,n,1);
        build2(1,n,1);
        for(int i=0;i<q;i++)
        {
            int op;
            scanf("%d",&op);
           // cout<<op<<endl;
            if(op==1)
            {
                int u,v;ll w;
                scanf("%d%d%lld",&u,&v,&w);
                add(u,v,w);
            }
            else
            {
                 int v,l,r;ll w;
                 scanf("%d%d%d%lld",&v,&l,&r,&w);
                 //cout<<v<<" "<<l<<" "<<r<<""
                 if(op==2)
                 {
                     addedge1(1,n,l,r,v,w,1,1);//point to area
                 }
                 if(op==3)
                 {
                     addedge1(1,n,l,r,v,w,1,0);
                 }
            }
        }
       dij(s);
       for(int i=1;i<=n;i++)
       {
           printf("%lld ",d[i]==INF?-1:d[i]);
       }
       printf("\n");

    }

 return 0;
  }

