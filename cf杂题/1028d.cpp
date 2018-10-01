#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<ll>s;
const ll mod=1e9+7;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        char op[10];ll p;
        ll ans=1;ll res=1;
        ll ab=0;ll as=1e9+10;
        s.insert(ab);s.insert(as);
        for(int i=1;i<=n;i++)
         {
         scanf("%s%lld",op,&p);
         if(op[1]=='D')
         {
             s.insert(p);
             if(p>=ab&&p<=as) res++;
         }
         else
         {
             if(p<ab||p>as)
               ans=0;
            if(ans)
            {
                if(p!=ab&&p!=as)
                   ans=(ans*2)%mod;
                s.erase(p);res=1;
                set<ll>::iterator it;
                it=s.lower_bound(p);
                as=*(it);
                ab=*(--it);
            }
         }
         }
        if(res) ans=(ans*res)%mod;
        //  if(ans&&s.size()) ans=(ans*(s.size()-1))%mod;
         printf("%lld\n",ans);

    }
}