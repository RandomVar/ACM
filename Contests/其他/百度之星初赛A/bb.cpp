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
const int N = 1 << 20;
list<int> que[N];

int main()
{
    int n, m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i = 1; i <= n; i++) que[i].clear();
        
        while (m--)
        {
            int op,u,v,w,val;
            scanf("%d",&op);
            if (op == 1)
            {
                scanf("%d%d%d",&u,&w,&val);
             
                if (w == 0)
                    que[u].push_front(val);
                else
                    que[u].push_back(val);
            }
            else if (op == 2)
            {
                scanf("%d%d",&u,&w);
                if (!que[u].empty())
                {
                    if (w == 0)
                    {
                        printf("%d\n",que[u].front());
                
                        que[u].pop_front();
                    }
                    else
                    {
                        printf("%d\n",que[u].back());
                     
                        que[u].pop_back();
                    }
                }
                else
                printf("-1\n");
            }
            else
            {
                scanf("%d%d%d",&u,&v,&w);
                if (!que[v].empty())
                {
                    if (w == 0)
                        que[u].splice(que[u].end(), que[v]);
                    else
                    {
                        que[v].reverse();
                        que[u].splice(que[u].end(), que[v]);
                    }
                    que[v].clear();
                }
            }
        }
    }
}

