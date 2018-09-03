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
int n,q;
const int maxn= 1e5+100;
const int N= 30;
vector<int>edge[maxn];
int fa[maxn][N+5];
int deep[maxn];

// int p[maxn];



void dfs(int u,int pre){
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i];
    if(v==pre) continue;
    fa[v][0]=u;//should give fa[v][0] value
    deep[v]=deep[u]+1; //also can preprocessing distance here
    dfs(v,u);
  }
}

void bz(){

 for(int j=1;j<=N;j++)
    for(int i=1;i<=n;i++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
}

int lca(int u,int v){
  if(deep[u]<deep[v]) swap(u,v);
  int dc=deep[u]-deep[v];
  for(int i=0;i<N;i++){
    if((1<<i)&dc)//move u to dc+u
        u=fa[u][i];
  }
  if(u==v) return u;
  for(int i=N-1;i>=0;i--){
    if(fa[u][i]!=fa[v][i]){
        u=fa[u][i];v=fa[v][i];
    }
  }
  u=fa[u][0];//on the next level of lca,just move up one
  return u;
}

void init(){
    for(int i=0;i<=n;i++)
     edge[i].clear();
   mem(deep,0);
   // deep[0]=deep[1]=0;
   //  for(int i=0; i<=n; i++)
    //    p[i]=i;
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    

    while(scanf("%d%d",&n,&q)==2)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            int y;
            scanf("%d",&y);
           edge[y+1].pb(i);
           // fa[i][0]=y+1;
          //if(y!=-1)  Union(i,y+1);
        }
        
     
    dfs(0,-1);
       bz();
    //    deep[i]=deep[fa[u][i]]

        // bz();
        

        for(int i=0;i<q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int flag=0;
            x++;y++;
            if(lca(x,y)==y)
             flag=1;
            // if(Find(x)==Find(y))
            //  {
                 //cout<<1<<endl;
            
            //  if(lca(x,y)==y)
            //   flag=1;
            //  }
            //int flag=query(y,x);//y is father
            if(flag)
              printf("Yes\n");
            else printf("No\n");
        }
    }
 return 0;
  }

