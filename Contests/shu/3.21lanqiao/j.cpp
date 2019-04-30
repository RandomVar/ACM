#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,k;
  while(cin>>n>>m>>k)
  {
    int flag=0;
    flag=(flag+n%2)%2;
    flag=(flag+m%2)%2;
    flag=(flag+k%2)%2;
    if(flag) cout<<"win"<<endl;
    else cout<<"lose"<<endl;
  }
}