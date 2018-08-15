#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1e5+5;
int fa[N];
ll rnk[N];
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
    rnk[x]=rnk[x]^rnk[temp];
    return fa[x];
}

int main()
{
    int n,m;
    while(cin>>n>>m){
        Init(n+1);
        int flag=0;
    for(int i=1;i<=m;i++){
         int u,v;
         ll k;
        scanf("%d%d%lld",&u,&v,&k);
        v++;
        int ru=Find(u);
        int rv=Find(v);
        if(ru!=rv) {
            fa[ru]=rv;
            rnk[ru]=k^rnk[u]^rnk[v];
        }
        else
        {
            if((rnk[v]^rnk[u])!=k) {flag=1;cout<<i<<endl;}
        }
    }
    if(!flag) cout<<-1<<endl;
    }
    return 0;
}
