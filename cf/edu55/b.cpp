#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int shu[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        string s;
        cin>>s;
        int k=0;
        int cnt=0;
        int fir=-1;
        int las=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='G')
            {
              cnt++; 
            }
            else 
            {
                shu[++k]=cnt;
                cnt=0;
            }
        }
        shu[++k]=cnt;
        for(int i=1;i<=k;i++)
        {
            if(shu[i]&&fir==-1)
              fir=i;
            if(shu[i])
             las=i;
        }
        int ans=0;
        for(int i=1;i<=k;i++)
        {
         if((fir!=-1&&fir<i)||(las!=-1&&las>i+1))   
            ans=max(ans,shu[i]+shu[i+1]+1);
        else ans=max(ans,shu[i]+shu[i+1]);
        }
         cout<<ans<<endl;
       
    }
}