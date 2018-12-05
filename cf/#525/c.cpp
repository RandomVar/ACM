#include<bits/stdc++.h>
using namespace std;
int a[2200];
int main()
{
    int n;
    while(cin>>n)
    {
        int ma=0;
        for(int i=1;i<=n;i++)
        cin>>a[i],ma=max(ma,a[i]);
         int a1=1e6-ma-1;
         cout<<n+1<<endl;
         cout<<1<<" "<<n<<" "<<a1<<endl;
        for(int i=1;i<=n;i++)
         a[i]+=a1;
        //  int pre=0;
         for(int i=1;i<=n;i++)
        {
            // int c=pre+1;
            // while(a[i]%c<=pre)
            // {
            //    c++;
            // }
            cout<<2<<" "<<i<<" "<<a[i]-i<<endl;
        //    pre=a[i]%c;
        }
      
    }
}