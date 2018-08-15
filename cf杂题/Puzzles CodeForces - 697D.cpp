/*
给一棵树，遍历这棵树，问到达每一个点的时间的期望

dfs求出每个点子树的大小
点t的期望 = 父节点的期望 + 1/2（先遍历该节点） + 1/2 + 兄弟节点的子树大小和/2 （先遍历兄弟节点） 
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
vector<int>edge[maxn];
double dp[maxn];
double sz[maxn];

void dfs1(int x)
{
    for(int i=0;i<edge[x].size();i++)
    {
        int t=edge[x][i];
        dfs1(t);
        sz[x]+=sz[t]+1;
    }
}
void dfs2(int x)
{
    for(int i=0;i<edge[x].size();i++)
    {
        int t=edge[x][i];
        dp[t]=(sz[x]-sz[t]-1)/2.0+dp[x]+1;
        dfs2(t);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=2;i<=n;i++)
          {
              int v;
              cin>>v;
              edge[v].push_back(i);
          }
        dfs1(1);
        dp[1]=1;
        dfs2(1);
        for(int i=1;i<=n;i++)
          printf("%.7lf ",dp[i]);
        printf("\n");
          //cout<<dp[i]<<" ";
          //cout<<endl;
    }
}