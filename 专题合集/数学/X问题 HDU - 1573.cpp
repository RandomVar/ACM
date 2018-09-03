#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=20;
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0&&b==0) return -1;
    if(b==0){x=1;y=0;return a;}
    ll d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll m0[maxn];
ll b[maxn];
ll dg;

ll china(ll n)
{
    ll a,bb,d,x,y,dm;
    ll c,c1,c2;
    a=m0[1]; c1=b[1];
    for (int i=2; i<=n; i++)
    {
        bb=m0[i]; c2=b[i];
        d=ex_gcd(a, bb,x, y);
        dm=bb/d;
        c=c2-c1;
        if (c%d) return -1;
        x=((x*c/d)%dm+dm)%dm;//x可能为负
        c1=a*x+c1;
        a=a*bb/d;
    }
    dg=a;//dg是最大公约数
    if (!c1)//考虑c1为0的情况
    {
        c1=1;
        for (int i=1; i<=n; i++)
        {
            c1=c1*m0[i]/__gcd(c1, m0[i]);
        }
        dg=c1;//此时dg为最小公倍数
    }
    return c1;//c1为最小的X
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll M=1;
        ll n;int m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
         cin>>m0[i];
         for(int i=1;i<=m;i++)
          cin>>b[i];
        ll x=china(m);
        //cout<<x<<endl;
        if(x==-1||x>n) cout<<0<<endl;
        else cout<<(n-x)/dg+1<<endl;
    }
}
