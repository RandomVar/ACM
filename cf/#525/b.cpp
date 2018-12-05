#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+100;
ll a[maxn];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        for(int i=1;i<=n;i++)
         cin>>a[i];
         sort(a+1,a+1+n);
         ll pre=0;
         int i;int cnt=0;
        for(i=1;i<=n;i++)
        {
            if(cnt==k) break;
            if(a[i]-pre>0)
            {
                cnt++;
                cout<<a[i]-pre<<endl;
                pre+=a[i]-pre;
            }
            else continue;
        }
         for(int c=cnt+1;c<=k;c++)
          cout<<0<<endl;
    }
}