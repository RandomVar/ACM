#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
long long a[100000];
long long b[1000];
ll gcd(ll a,ll b){
         if(a < b){
                   swap(a,b);
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}

struct tt
{
    long long n;
    long long num;
}c[100000];
int main()
{
    int T,n;
    long long k,p,pp,m,m1,mm,MIN;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        k=0;p=0;pp=false;m=0;mm=0;MIN=99999999999;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            MIN=min(MIN,a[i]);
        }

        for(int i=0;i<min(n,15);i++)
        {
            for(int j=0;j<min(n,15);j++)
            {
                if(i==j)continue;
                //cout<<i<<" "<<j<<endl;
                b[i]=gcd(a[i],a[j]);
                //cout<<b[i]<<endl;
                 for(int j=0;j<p;j++)
                {
                    if(c[j].n==b[i])
                    {
                        c[j].num++;
                        pp=true;
                        break;
                    }
                }
                if(pp==false)
                {
                    c[p].n=b[i];
                    c[p].num++;
                    p++;
                }
                if(pp==true)pp=false;
            }
        }
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(c[j].n!=1)
                {
                    if(c[i].n%c[j].n==0){c[j].num+=c[i].num;}
                }
            }
        }
        for(int i=0;i<p;i++)
        {
            if(c[i].n==MIN)m1=c[i].num;
            m=max(m,c[i].num);
        }
        if(m1==m)
        {
            for(int i=0;i<p;i++)
                if(m1==c[i].num)mm++;
        }
        for(int i=0;i<p;i++)
            cout<<c[i].n<<" "<<c[i].num<<endl;
        for(int i=0;i<p;i++)
        {
            if(mm>=2&&c[i].n==1)continue;
            if(c[i].num==m)
            {
                cout<<c[i].n<<endl;
                break;
            }
        }
    }
}
