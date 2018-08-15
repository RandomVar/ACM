#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=40;
ll c[43][43];
void init()
{
for(int j=0;j<N;j++)
    c[j][0]=1;
for(int i=0;i<N;i++)
   for(int j=1;j<N;j++)
    {
     if(i==j) c[i][j]=1;
      else if(i<j) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i-1][j]); 
    }
}
int main()
{
    int n,a,b;
    init();
    while(cin>>n>>a>>b)
    {
        cout<<c[n+a][n]*c[n+b][n]<<endl;
    }
}