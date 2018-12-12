#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int a[maxn];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int x=n;int y=0;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            y=max(y,a[i]);
        }
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--)
        {
            if(a[i]>=y)
              sum+=a[i]-1,y--;
            else sum+=a[i]-1-(y-a[i]),y=a[i]-1;
            // cout<<sum<<endl;
        }
        if(y>0) sum-=y;
        cout<<sum<<endl;
    }
}