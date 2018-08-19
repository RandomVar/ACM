#include<bits/stdc++.h>
using namespace std;
int a[210][210];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n%2==1)
           {
               printf("impossible\n");
              continue;
           }
        else
        {
            printf("possible\n");
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n-i;j++)
                   a[i][j]=1;
                if(i<=n/2)  a[i][n-i+1]=0;
                else a[i][n-i+1]=1;
                for(int j=n-i+2;j<=n;j++)
                {
                    a[i][j]=-1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
 
             for(int j=1;j<n;j++)
               printf("%d ",a[i][j]);
          printf("%d\n",a[i][n]);
        }
 
    }
    return 0;
}