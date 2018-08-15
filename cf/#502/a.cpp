#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
     int n;
     while(cin>>n)
     {
         int id=0;
         int ans=0;
         //memset(a,0,sizeof(a));
         for(int i=1;i<=n;i++)
         {
             int a=0;
             int t;
             for(int j=0;j<4;j++)
               cin>>t,a+=t;
           if(ans<a)
               ans=a,id=i;
               //cout<<a<<endl;
         }
         cout<<id<<endl;
         
     }

}
