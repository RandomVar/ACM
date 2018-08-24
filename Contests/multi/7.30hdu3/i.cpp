#include<bits/stdc++.h>
using namespace std;
int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
         int n,m;
         scanf("%d%d",&n,&m);
         for(int i=1;i<=n;i++)
          scanf("%d",&a[i]);
         for(int i=1;i<=n;i++)
          scanf("%d",&v[i]);
        for(int i=2;i<=n;i++)
            for(int x=1;x<=m;x++)
              for(int y=1;y<=x;y++)
                for(int z=1;z<=y;z++)
                {
                  f[i+1][a[i+1]][a][]=f[i][x][y][z];
               }
     }
}