#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
         cin>>s;
         m--;
         int ans=0;
         for(int i=1;i<=m;i++)
          if(s[i]=='R') ans++;
          int ans2=0;
        for(int i=m;i<n-1;i++)
          if(s[i]=='L') ans2++;
     cout<<min(ans,ans2)<<endl;
    }
}