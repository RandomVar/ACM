#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    for(int i=1;i<=6;i++)
      cin>>a[i];
    int ans=0;
    if(a[1]>a[5])
      ans+=a[5],a[5]=0,a[1]-=5;
    else
     ans+=a[1],a[1]=0,a[5]-=a[1];
    if(a[2]>a[6])
      ans+=a[6],a[6]=0,a[2]-=5;
    else
     ans+=a[2],a[2]=0,a[6]-=a[2];
     if(a[3]>a[4])
      ans+=a[4],a[4]=0,a[3]-=5;
    else
     ans+=a[3],a[3]=0,a[4]-=a[4];
    cout<<ans<<endl;
    // int x;
    // cin>>x;
}