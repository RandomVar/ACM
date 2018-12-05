#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
int a[maxn];
vector<int>v[maxn];
int sum[maxn];
int main()
{
    int n,c;
    while(cin>>n>>c)
    {
        int mm=0;
        for(int i=1;i<=n;i++)
         cin>>a[i],mm=max(mm,a[i]);
        for(int i=1;i<=n;i++)
        {
            v[a[i]].push_back(i);
           sum[i]=sum[i-1];
           if(a[i]==c)
            sum[i]++;
        }
        int ans=0;
        for(int i=1;i<=mm;i++)
        {
            if(v[i].size()==0) continue;
            if(i==c) continue;
            int mi=0;
            for(int j=0;j<v[i].size();j++)
            {
                int x=v[i][j];
                int c=j-sum[x];
                mi=min(mi,c);
                ans=max(ans,c+1-mi);
            }
        }
        ans+=sum[n];
        cout<<ans<<endl;
    }
}