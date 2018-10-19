#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double eps=1e-7;
ll b[65];
ll val[65];
void init()
{
    b[1]=1;
    for(int i=2;i<=63;i++)
     b[i]=b[i-1]*2;
}
int main()
{
    int q;
    init();
    while(scanf("%d",&q)==1)
    {
     
        int t;ll x;ll k;
        for(int i=1;i<=q;i++)
        {
            scanf("%d%lld",&t,&x);
            int y=upper_bound(b+1,b+64,x)-b;
            y--;
            //  int y=(log(x)/log(2.0)+eps)+1;
            //  cout<<y<<endl;
            ll e;
            if(t==1)
            {
                scanf("%lld",&k);
                e=k%b[y];
                val[y]=(val[y]+e+b[y])%b[y];
                e=2*k%b[y+1];
                val[y+1]=(val[y+1]-e+b[y+1])%b[y+1];
            //   cout<<val[y+1]<<endl;
            }
            else if(t==2)
            {
                scanf("%lld",&k);
                e=k%b[y];
                val[y]=(val[y]+e+b[y])%b[y];
            }
            else if(t==3)
            {
                printf("%lld ",x);                                 
                int c=y;ll v=x;
                while(c>1)
                {
                    v=(v-b[c]+val[c])%b[c]+b[c];
                    // cout<<"*"<<b[c]<<" "<<v<<" "<<val[c]<<endl;
                    v=(v>>1);
                    c--;
                    // v=(v+val[c])%b[c]+b[c];
                    printf("%lld ",v);
                }
                printf("\n");
            }
        }
    }
}