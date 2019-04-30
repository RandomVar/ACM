#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+100;
int righ[maxn];
int main()
{
  int n;
  while(cin>>n)
  {
    string s;
    cin>>s;
    if(n%2||s[0]==')'||s[n-1]=='(')
    {
      cout<<":("<<endl;
      continue;
    }
    string ans="(";
    int flag=1;
    righ[n-1]=0;
    for(int i=n-2;i>=1;i--)
    {
      if(s[i]=='(')
        {//( ?
        righ[i]=max(0,righ[i+1]-1);
        }
      else if(s[i]==')')
        righ[i]=righ[i+1]+1;
      else righ[i]=max(0,righ[i+1]-1);
    }
    int st=0;
    for(int i=1;i<n-1;i++)
    {
       if(s[i]=='(') 
       {
         ans+='(';
         st++;
       }
       else if(s[i]=='?')
       {
         if(st<=righ[i+1])
            {
             ans+='(';
              st++;
            }
          else
          {
            ans+=')';
            st--;
          }
       }
       else 
       {
         ans+=')';
         st--;
       }
       if(st<righ[i+1])
         flag=0;
        if(st<0)
         flag=0;
    }
    if(st!=0) flag=0;
    ans+=')';
    if(!flag) cout<<":("<<endl;
    else 
    {
          cout<<ans<<endl;
    }
  }
}