#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int q;
    while(cin>>q)
    {
        for(int i=1;i<=q;i++)
        {
            ll l,r;
            cin>>l>>r;
          if(l%2==0)
          {
              if(r%2)
              {
                  cout<<-(r-l+1)/2<<endl;;
              }
           else
           {
               cout<<-(r-l)/2+r<<endl;
           }
          }
          else
          {
              if(r%2==0)
              {
                  cout<<(r-l+1)/2<<endl;
              }
              else
              {
                  cout<<(r-l)/2-r<<endl;
              }
          }
          
        }
    }
}