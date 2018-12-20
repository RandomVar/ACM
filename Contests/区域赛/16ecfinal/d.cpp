#include<bits/stdc++.h>
#define ll long long
#define mkr make_pair 
using namespace std;
const int maxn=3e5+100;
ll a[maxn];
multiset<ll>st;
typedef pair<ll,int>P;
int n,k;
int check(int mid)
{
    if(mid==0) return 1;
    int ans=0;
    int i=1;
    queue<P>que;
    for(int i=1;i<=mid;i++)
     que.push(mkr(0,0));
        while(!que.empty()&&i<=n)
        {
             P p=que.front();
             while(i<=n&&p.first*2>a[i]) i++;
             if(i>n) return ans>=mid;
             if(p.first*2<=a[i])
             {
                 que.pop();
                 p.second++;
                //  cout<<p.first<<" "<<a[i]<<endl;
                 if(p.second==k)
                  ans++;
                else que.push(mkr(a[i],p.second));
                  i++;
             }
    }
    return ans>=mid;
}
int main()
{
   int t;
   scanf("%d",&t);
   int cas=0;
   while(t--)
   {

       scanf("%d%d",&n,&k);
       for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
        printf("Case #%d: ",++cas);
        if(k==1)
        {
            printf("%d\n",n);
            continue;
        }
       sort(a+1,a+1+n);
       int l=0;int r=n;
       int ans;
       while(l<=r)
       {
          int mid=(l+r)/2;
          if(check(mid))
            {
                //cout<<mid<<endl;
                ans=mid;l=mid+1;
            }
        else r=mid-1;
       }
       printf("%d\n",ans);
   }
}