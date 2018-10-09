#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
bitset<1005>bt[11];
bitset<1005>ans;
char s[maxn];
int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
         int x,y;
        for(int i=1;i<=n;i++)
        {
          scanf("%d",&x);
          for(int j=0;j<x;j++)
           scanf("%d",&y),bt[y].set(i);
        }
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            ans<<=1;
            ans.set(1);
            ans&=bt[s[i]-'0'];
            if(ans[n]==1)
            {
                char cc=s[i+1];
                s[i+1]='\0';
                puts(s+i-n+1);
                s[i+1]=cc;
                // for(int j=i-n+1;j<=i;j++)
                //    putchar(s[j]);
                // //   printf("%c",s[j]);
                // // printf("\n");
                // putchar('\n');
            }
        }
    }
}