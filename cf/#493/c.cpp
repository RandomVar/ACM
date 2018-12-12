#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int n;ll x,y;
  string s;
  while(cin>>n>>x>>y)
  {
      cin>>s;
      ll cnt=0;
      for(int i=0;i<n;i++)
        if(s[i]=='0')
        {
          cnt++;
          while(i<n&&s[i]=='0')
            i++;  
        }
    if(x<y&&cnt) cout<<(cnt-1)*x+y<<endl;
    else cout<<cnt*y<<endl;
  }
}