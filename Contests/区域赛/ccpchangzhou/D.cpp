#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T,p1,n,pn,x;
    cin>>T;
    while(T--)
    {
        p1=0;
        scanf("%d%d",&n,&pn);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==1)p1++;
        }
        if(n-p1>1)cout<<"Yes\n";
        else if(n==p1)
        {
            if(pn==1)
            {
                if(p1%3==1||p1%3==2)cout<<"Yes\n";
                else cout<<"No\n";
            }
            else
            {
                if(p1%3==1)cout<<"No\n";
                else cout<<"Yes\n";
            }
        }
        else
        {
            if(p1%3==1)cout<<"Yes\n";
            else
            {
                if(pn==1)cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }

}
