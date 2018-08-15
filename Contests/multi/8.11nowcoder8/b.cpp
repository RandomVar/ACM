#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt;
int check()
{
    for(int i=1;i<=n;i++)
      
}
void dfs(int pos)
{
    if(pos==0){
        if(check()) cnt++;
    }
    for(int i=1;i<=n;i++)
      {
          a[pos]=i;
          dfs(i);
      }
}

int main()
{
   int n;
   while(cin>>n)
   {
       dfs(n);
   }
}