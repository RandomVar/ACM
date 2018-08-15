#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=200010;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<vector<int> > edge(maxn);
int st[maxn],ed[maxn];
int n;int tol;
int f[maxn];
int tree[maxn];
void dfs(int x){
  st[x]=tol;
  for(int i=0;i<edge[x].size();i++){
        tol++;
    int t=edge[x][i];
    //if(t==pre) continue;
    dfs(t);
  }
  ed[x]=tol;
}
/*
���2^p(����p: x �Ķ����Ʊ�ʾ���У�
����������һ��1��λ��)����6�Ķ����Ʊ�ʾΪ110��
�����������Ϊ0����һ��Ϊ1����p=1����Lowbit(6) = 2^1 = 2
�����ư�λ�����㣬���ز�����x��2�����η�����
*/
int lowbit(int x){//���x�ĸ��׽ڵ�
return x&(-x);
}
int sum(int x){
  int ret=0;
  while(x>0){
    ret+=tree[x];
    x-=lowbit(x);
  }
return ret;
}

void update(int x,int d){
    if(x<0) return;
   while(x<=n){
    tree[x]+=d;
    x+=lowbit(x);
   }
}

int main(){
  //int n;
  while(scanf("%d",&n)==1){
        memset(tree,0,sizeof(tree));
        memset(f,0,sizeof(f));
        memset(st,0,sizeof(st));
        memset(ed,0,sizeof(ed));
        for(int i=0;i<=n;i++)
            edge[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        //cin>>u>>v;
        edge[u].pb(v);
        //edge[v].pb(u);
    }
   tol=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        f[i]=1;
        update(i,1);
        }

    int m;
    scanf("%d",&m);
    //cin>>m;
    for(int i=0;i<m;i++){
        char c;int r;
        getchar();
        scanf("%c%*c%d",&c,&r);
       // cin>>c;cin>>r;
        if(c=='C') {if(f[r]) update(st[r],-1);
                  else update(st[r],1);f[r]=!f[r];}
        else if(c=='Q') {
                printf("%d\n",sum(ed[r])-sum(st[r]-1));
                //cout<<sum(ed[r])-sum(st[r]-1)<<endl;
                //cout<<sum(ed[r])-sum(st[r]-1)<<endl;
    }}

  }
return 0;
}

