#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        if(y<x) 
        {
            int x1=n-x+1;
            int y1=n-y+1;
            x=x1;y=y1;
        }
        // cout<<x<<" "<<y<<endl;
        int a1=1e9+10;int a2=1e9+10;
        if((y-x)%d==0)
        {
            cout<<(y-x)/d<<endl;
           continue;
        }
        if((y-1)%d==0)
        {
            // cout<<y-1<<" "<<d<<"?"<<endl;
            a1=(x-1)/d;
            a1+=((x-1)%d==0?0:1);
            // cout<<a1<<endl;
            a1+=(y-1)/d;
        }
        if((n-y)%d==0)
        {
            a2=(n-x)/d;
           // cout<<a2<<endl;
            a2+=((n-x)%d==0?0:1);
          //  cout<<a2<<endl;
            a2+=(n-y)/d;
        }
        if(a1==1e9+10&&a2==1e9+10)
         cout<<-1<<endl;
         else cout<<min(a1,a2)<<endl;        
    }
}