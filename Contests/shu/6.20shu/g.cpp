#include<iostream>
#include<cstdio>
using namespace std;
const int N=2*1e5+100;
int fa[N];
int rnk[N];
void Init(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        rnk[i]=0;
    }
}
int Find(int x)
{
    if(x==fa[x])return x;
    int temp=fa[x];
    fa[x]=Find(fa[x]);
    rnk[x]=rnk[x]+rnk[temp];
    return fa[x];
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        Init(n+1);

        int cnt=0;
    for(int i=1;i<=m;i++){
         int u,v;
         int k;
        scanf("%d%d%d",&u,&v,&k);
        v++;
        int ru=Find(u);
        int rv=Find(v);
        if(ru!=rv) {
            fa[ru]=rv;
            rnk[ru]=k-rnk[u]+rnk[v];
        }
        else
        {
            if((-rnk[v]+rnk[u])!=k) {cnt++;}
        }
    }
     printf("%d\n",cnt);
    }
    return 0;
}
