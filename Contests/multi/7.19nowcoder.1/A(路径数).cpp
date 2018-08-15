/*
首先转化成从左上到右下为 0-1-2 过渡

考虑 01 和 12 的分界线 是 (n, 0) 到 (0, m) 的两条不相交（可重合）路径 
平移其中一条变成 (n-1, -1) 到 (-1, m-1) 
变成起点 (n, 0) 和 (n-1, -1)，终点 (0, m) 和 (-1, m-1) 的严格不相交路径 
套 Lindström–Gessel–Viennot lemma 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c[2100][2100];
const int N=2010;
const ll mod=1e9+7;
void init()
{
for(int j=0;j<N;j++)
    c[j][0]=1;
for(int i=0;i<N;i++)
   for(int j=1;j<N;j++)
    {
     if(i==j) c[i][j]=1;
      else if(i<j) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod; 
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n,m;
   init();
   while(cin>>n>>m)
   {
       cout<<(c[n+m][m]*c[n+m][m]%mod-c[n+m][m-1]*c[n+m][n-1]%mod+mod)%mod<<endl;
   }
}