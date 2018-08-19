#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
char s[maxn][maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            scanf("%s",s[i]+1);
        int p=0,q=0;
        bool flag=false;
        for(int j=1;j<M/2;j++)
        {
            flag=false;
            for(int i=1;i<=N/2;i++)
            {
                if(s[i][j]!=s[i][M-j+1])
                    flag=true;
                if(s[i][j]!=s[N-i+1][j])
                    flag=true;
                if(s[i][j]!=s[N-i+1][M-j+1])
                    flag=true;
            }
            if(!flag)
                p++;
            else
                break;
        }
        for(int i=1;i<N/2;i++)
        {
            flag=false;
            for(int j=1;j<=M/2;j++)
            {
                if(s[i][j]!=s[N-i+1][j])
                flag=true;
                if(s[i][j]!=s[i][M-j+1])
                    flag=true;
                if(s[i][j]!=s[N-i+1][M-j+1])
                    flag=true;
            }
            if(!flag)
            q++;
            else
            break;
        }
        printf("%d\n",p*q);
    }
    return 0;
}