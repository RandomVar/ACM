#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n)
    {
        cout<<n<<endl;
        int ans=0;
        while(n>1)
        {
            n=(n+2)/3;
            ans++;
        }
        cout<<"Times:";
        cout<<ans<<endl;
    }
}