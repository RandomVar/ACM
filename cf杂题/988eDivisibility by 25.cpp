/*
毒瘤
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bit[20];
int wei[13];
int main()
{
    ll n;
    while(cin>>n)
    {
        memset(bit,0,sizeof(bit));
        memset(wei,-1,sizeof(wei));
        int flag=-1;
        ll t=n;int k=0;
        while(t)
        {
            bit[k++]=t%10;
            t/=10;
        }
        for(int i=k-1;i>=0;i--)
        {
             if(bit[i]==0&&wei[0]!=-1) flag=wei[0];
            wei[bit[i]]=i;
        }
        int ans=1e5;
        if(wei[0]!=-1&&wei[5]!=-1)
        {
            int x=wei[5]+wei[0]-1;
            if(wei[5]<wei[0]) x++;//5 is back
            if(wei[5]==k-1)
            {
                int c=k-2;
                int ji=0;
                // cout<<x<<endl;
                while(c>=0&&bit[c]==0) c--,ji++;
                x+=ji;
                if(wei[0]==c+1) x--;
                // cout<<c<<" "<<ji<<endl;
                // cout<<ji<<" "<<c<<endl;
            }
            ans=min(ans,x);
        }
        if(wei[0]!=-1&&flag!=-1)
          ans=min(ans,wei[0]+flag-1);
        if(wei[2]!=-1&&wei[5]!=-1)
        {
            int x=wei[2]+wei[5]-1;
            if(wei[2]<wei[5]) x++;
          if(wei[5]==k-1||wei[2]==k-1)
          {
              int c=k-2;
              int ji=0;
              if(wei[2]==k-2||wei[5]==k-2) c=k-3;
              while(c>=0&&bit[c]==0) c--,ji++;
              x+=ji;
          }
          ans=min(ans,x);
        }
        if(wei[7]!=-1&&wei[5]!=-1)
        {
            int x=wei[7]+wei[5]-1;
            if(wei[7]<wei[5]) x++;
            if(wei[5]==k-1||wei[7]==k-1)
          {
              int c=k-2;
              int ji=0;
              if(wei[7]==k-2||wei[5]==k-2) c=k-3;
              while(c>=0&&bit[c]==0) c--,ji++;
              x+=ji;
          }
    
             ans=min(ans,x);
        }
        if(ans==1e5) cout<<-1<<endl;
        else cout<<ans<<endl;

    }
}