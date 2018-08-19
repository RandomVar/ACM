/*
给一个字符串s
对于环形的s，将以第i个字符开头的字符串中相同的分为一组，按字典序输出所有的组

KMP做法
*/
#include<bits/stdc++.h>
using namespace std;
// 返回y中x的个数
const int maxn =1e6+100;
int fail[maxn*2];
vector<int>vec[maxn];
int p[maxn];
void init(int n)
{
    for(int i=0; i<=n; i++)
        p[i]=i;
    for(int i=0;i<=n;i++)
     vec[i].clear();
}
int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}

int Union(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)
        return 0;
    if(y1<x1)
      p[x1]=y1;
    else p[y1]=x1;
      return 1;
}
void getfail(char *x)
{
    int m=strlen(x);
    int i = 0, j = fail[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = fail[j];
        fail[++i] = ++j;
    }
}
int kmp(char *x,char *y) //x是模式串，y是主串
{
    int i, j, ans;
    i = j = ans = 0;
    getfail(x);
    int m=strlen(x);
    int n=strlen(y);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = fail[j];
        i++, j++;
        if (j >= m) ans++, j = fail[j];
    }
    return ans;
}

char s[maxn*2];
int main()
{
   
    while(scanf("%s",s)!=EOF)
    {
        
        int len=strlen(s);
        for(int i=len;i<2*len;i++)
          s[i]=s[i-len];
        s[2*len]='\0';
        getfail(s);
        int k=fail[2*len];
        // cout<<k<<endl;
        init(len);
        for(int i=0;i<len;i++)
        {
           if(i+2*len-k<len) Union(i,i+2*len-k);
        //    cout<<i<<" "<<i+2*len-k<<endl;
        }
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            vec[Find(i)].push_back(i);
            if(Find(i)==i) cnt++;
            // cout<<i<<" "<<Find(i)<<endl;
        }
         printf("%d\n",cnt);
        for(int i=0;i<len;i++)
        {
            if(vec[i].size())
            {
                int len=vec[i].size();
                printf("%d",len);
                // cout<<len;
                for(int j=0;j<len;j++)
                  printf(" %d",vec[i][j]);
                printf("\n");
                //  cout<<" "<<vec[i][j];
                //  cout<<endl;
            }
        }
    }
  
}