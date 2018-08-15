#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
typedef long long ll;
ll p[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    while(cin>>N)
    {
        for(int i=1;i<=N;i++)
            cin>>p[i];
            ll ans=100;
            ll pre=0;
            ll pri=0;
            p[0]=0;
            p[N+1]=600;
           for(int i=1;i<=N;i++)
           {
              // if(p[i]>ans)
                // continue;
             //  if(p[i]==p[i-1]) 
              //   continue;
               if(p[i]>=p[i-1])
               {
                   ans+=p[i]*pre-pre*pri;
                   pre=0;
                   pri=0;
               }
               if(p[i]<=p[i+1])
               {
                  pre=ans/p[i];
                  if(pre>1e5) pre=1e5;
                  pri=p[i];
               }
              // cout<<ans<<endl;
           }
           cout<<ans<<endl;
       /* ll now=100;
        int own=0;
        for(int i=1;i<N;i++)
        {
            if(p[i]==p[i+1])
                continue;
            if(p[i]>p[i+1])
            {
                now+=1LL*own*p[i];
                own=0;
            }
            else
            {
                int k=now/p[i];
                if(own+k<=100000)
                {
                    now-=1LL*k*p[i];
                    own+=k;
                }
                else
                {
                    now-=1LL*(100000-own)*p[i];
                    own=100000;
                }
            }
        }
        now+=own*p[N];*/
        //cout<<now<<endl;
    }
    return 0;
}
