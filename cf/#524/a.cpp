#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        ll a=1LL*n*2;
        ll b=1LL*n*5;
        ll c=1LL*n*8;
        a=a/k+(a%k==0?0:1);
        b=b/k+(b%k==0?0:1);
        c=c/k+(c%k==0?0:1);
        cout<<a+b+c<<endl;
    }
}