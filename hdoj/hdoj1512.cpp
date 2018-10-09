#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
const int maxn=1e5+100;
__gnu_pbds::priority_queue<int>que[maxn];
int p[maxn];
void init(int n)
{
    for(int i=0;i<=n;i++)
      p[i]=i;
}
void Find(int x)
{
    if(x==p[x])
     return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}
void Union(int x,int y)
{
    p[y]=x;
}
int main()
{
    int n;
    while(scanf("$d",&n)==1)
    {
        int x,y;
        init(n);
        for(int i=1;i<=n;i++)
        {
          scanf("%d",&x);
          que[i].clear();
          que[i].push(x);
        
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            int fx=Find(x);
            int fy=Find(y);
            if(fx==fy)
            {
                printf("-1\n");
                continue;
            }
           int mx=que[fx].top();
           int my=que[fy].top();
          que[fx].pop();que[fy].pop();
          mx/=2;my/=2;
          que[fx].push(mx);que[fy].push(my);
        
          que[fx].join(que[fy]);
          Union(fx,fy);
          printf("%d\n",que[fx].top());
        }

    }
}