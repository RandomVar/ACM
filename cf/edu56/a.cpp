#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        int i=7;
        while(n)
        {
            ans+=n/i;
            n=n%i;
            i--;
        }
        cout<<ans<<endl;
    }
}