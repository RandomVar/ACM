#include<bits/stdc++.h>
using namespace std;
vector<int>edge[50];
int vis[50];
map<string,int>mp;
int dfs(int x,int y)
{
    vis[x]=1;
    if(x==y) return 1;
    for(int i=0;i<edge[x].size();i++)
    {
        int v=edge[x][i];
        if(vis[v]) continue;
        if(dfs(v,y)) return 1;
    }
    return 0;
}
char s1[50];
char s2[50];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        // cout<<n<<endl;
        int f=0;
        mp.clear();
        int k=0;
        for(int i=0;i<50;i++)
         edge[i].clear();
         int x,y;
        //  cout<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s1);
        //    printf("%s\n",s1);
           if(mp.find(s1)==mp.end())
              mp[s1]=++k;
            x=mp[s1];
            scanf("%s",s2);
            if(mp.find(s2)==mp.end())
             mp[s2]=++k;
             y=mp[s2];
            //  cout<<s1<<s2<<endl;
             if(f) continue;
             memset(vis,0,sizeof(vis));
             int flag=dfs(y,x);
             if(flag)
             {
                 printf("%s %s\n",s1,s2);
                 f=1;
                 continue;
             }
                edge[x].push_back(y);

        }
        if(f==0) printf("0\n");
    }
}
