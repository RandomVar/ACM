#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cin>>x[1]>>y[1]>>x[2]>>y[2];
        cin>>x[3]>>y[3]>>x[4]>>y[4];
        s[1]=seg{x[1],x[2],y[1],1};
        s[2]=seg{x[1],x[2],y[2],-1};
        s[3]=seg{x[3],x[4],y[3],1};
        s[4]=seg{x[3],x[4],y[4],-1};
        for(int i=1;i<=4;i++)
         v.push_back(x[i]);
         sort(v.begin(),v.end());
         v.erase(unique(v.begin(),v.end()),v.end());
        sort(s+1,s+5);
        for(int i=1;i<=4;i++)
        {
            if(s[i].s==1)
            {
                ji[id1]++;
                ji[id2+1]--;
            }
            else
            {
                
            }
        }
    }

}