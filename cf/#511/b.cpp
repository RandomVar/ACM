#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int ans=0;
        int x,y;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            ans=max(ans,x+y);
        }
        cout<<ans<<endl;
    }
}