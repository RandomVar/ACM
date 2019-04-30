#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
   int len=s.size();
   stack<char>vec;
   vec.push(s[0]);
   int cnt=0;
   for(int i=1;i<len;i++)
   {
     if(!vec.empty()&&s[i]==vec.top())
     {
       vec.pop();
       cnt++;
     }
     else vec.push(s[i]);
   }
   if(cnt%2==0)
   {
     cout<<"Oh,no."<<endl;
   }
    else cout<<"Yes,you can win!"<<endl;
   
  }
}