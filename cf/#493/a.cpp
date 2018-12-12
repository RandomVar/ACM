#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int mm=1e9;int ans=-1;
        int sum=0; 
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(mm>x)
             {
                mm=x;ans=i;
            }
            sum+=x;
        }
        if(n==1) cout<<-1<<endl;
        else if(sum-mm==mm)
         cout<<-1<<endl;
         else 
         {
         cout<<1<<endl;
         cout<<ans<<endl;
         }
    }
}