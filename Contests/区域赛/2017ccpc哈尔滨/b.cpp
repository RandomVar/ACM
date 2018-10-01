#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int a[maxn];

int n,m,k;
int check(int mid)
{
    int s=1;int t=1;
    int ans=0;
    int cnt=0;
    // cout<<"*"<<mid<<endl;
    while(t<=n&&s<=n)
    {
     
       if(a[t]>mid)
       {
           cnt++;
       }
       if(cnt>=k)
       {
        //    cout<<"!"<<endl;
           ans+=n-t+1;
           if(a[s]>mid)
             cnt--;
            s++;
       }
       else if(t<n)
         t++;
      else break;
        //   cout<<ans<<endl;
       if(ans>=m) return 0;
    }
   
    if(ans>=m) return 0;
    return 1;
}
int b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
   
        scanf("%d%d%d",&n,&k,&m);
        for(int i=1;i<=n;i++)
         scanf("%d",&a[i]),b[i]=a[i];
       sort(b+1,b+1+n);
   

       int l=1;int r=n;
       int ans=0;
       while(l<=r)
       {
           int mid=(l+r)/2;
        //    cout<<mid<<endl;
           if(check(b[mid])==0)//bigger number >=m
           {
              l=mid+1;
           }
           else
           {
               ans=b[mid];
            //    cout<<mid<<" "<<b[mid]<<endl;
               r=mid-1;
           }
       }

       printf("%d\n",ans);
    }
}