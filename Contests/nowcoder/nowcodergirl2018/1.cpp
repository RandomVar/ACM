#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

    int t,s,q;
    while(cin>>t>>s>>q)
    {
    //    int k=t/(q-1);
    //    if(t%(q-1))
    //     k++;
    //     int flag=0;
    //     int l=0;
    //     int ans=0;
    //     for(int i=1;i<=k*q;i++)
    //     {
    //         if(i%q==0)
    //           l+=q-1;
    //         if(!flag)
    //         {
    //             if(l<s)
    //              continue;
    //              else{
    //                  flag=1;
    //                  ans++;
    //                  if(l==0)
    //                   flag=0;
    //              }
    //         }
    //         else 
    //         {
    //             if(l>0)
    //             l--;
    //             if(l==0)
    //              flag=0;
    //         }
    //     }
    //     cout<<ans<<endl;
       ll  now=0;
       ll cnt=0;
       ll  ans=0;
       while(ans<t)
       {
           now+=s;
           now+=now*(q-1);
            //  ll x=ans;
            // while((now+x)*q/(q-1)>=x-1)
            //    x++;
            // now+=x;
          // cout<<x<<" "<<now<<endl;
           cnt++;        
           ans=now/q*(q-1);                                   
           //cout<<now<<" "<<ans<<endl;      
        }
        cout<<cnt<<endl;
     }
}