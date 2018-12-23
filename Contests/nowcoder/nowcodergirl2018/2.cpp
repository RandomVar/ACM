#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int is[maxn];
void init()
{
    for(int i=3;i<maxn;i+=3)
      is[i]=1;
    //   for(int i=5;i<maxn;i+=5)
    //   is[i]=1;
}
int main()
{
    int n;
    init();
    while(cin>>n)
    {
         int ans=0;
         int pre=1;
         for(int i=5;i<=n;i++)
         {
             double cnt=0;
             for(int j=pre;j<=i;j++)
             {
                 double  x=pow(1.0*i,1.0*j)/pow(1.0*j,1.0*j);
                // cout<<x<<endl;
                 if(x>cnt)
                 {
                     pre=j;
                     cnt=x;
                 }
             }
            //  cout<<pre<<" "<<is[pre]<<endl;
           if(is[pre])
             ans+=i;
            else ans-=i;
         }
        cout<<ans<<endl;
    }
}