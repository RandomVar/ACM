#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n;
    while(scanf("%d%d",&k,&n)==2)
    {
        for(int i=1;i<=n;i++)
         scanf("%s",s[i]);
         int flag=0;
         int f=0;
         for(int i=1;i<=n;i++)
         {
             int len=strlen(s[i]);
             for(int j=0;j<len;j++)
              mp[flag][s[i][j]-'a']++;
            if(i!=1)
            {
                for(int j=0;j<26;j++)
                  if(mp[flag][j]!=mp[flag^1][j]) {f=0;break;}
               if(!f)
                 { printf("-1\n");break; }
            }
         }
         if(!f) continue;
         for(int i=0;i<k;i++)
           {
               if(s[0][i]!=s[1][i])
                 v.pb(i);
                else ans[i]=s[0][i];
           }
        if(v.size()==4)
        {
            int flag=0;
            for(int i=0;i<4;i++)
              for(int j=i+1;j<4;j++)
              {
                  if(s[0][v[i]]==s[1][v[j]]&&s[0][v[j]]==s[1][v[i]])
                     {
                         int x=-1,y=-1;
                       for(int k=0;k<4;k++)
                         if(x==-1&&v[k]!=v[i]&&v[k]!=v[j])
                             x=i;
                         else if(v[k]!=v[i]&&v[k]!=v[j])
                            y=i;
                      if(s[0][v[x]]==s[1][v[y]]&&s[0][v[y]]==s[1][v[x]])
                        {
                            flag=1;
                            ans[v[i]]=s[0][v[i]];
                            ans[v[j]]=s[0][v[j]];
                            ans[v[x]]=s[1][v[x]];
                            ans[v[y]]=s[1][v[y]];
                            for(int c=0;c<k;c++)
                              ans1[c]=ans[c];
                            ans1[v[i]]=ans[v[j]];
                            ans1[v[j]]=ans[v[i]];
                            ans1[v[x]]=ans[v[y]];
                            ans1[v[y]]=ans[v[x]];
                           break;
                        }}}
        }
        if(v.size()==3)
        {
            ans[v[0]]=s[0][v[0]];
            ans[v[1]]=s[0][v[2]];
            ans[v[2]]=s[0][v[1]];

         for(int i=0;i<k;i++)
           ans1[i]=ans2[i]=ans[i];

            ans1[v[0]]=s[0][v[1]];
            ans1[v[1]]=s[0][v[2]];
            ans1[v[2]]=s[0][v[0]];
            
            ans2[v[0]]=s[0][v[2]];
            ans2[v[1]]=s[0][v[0]];
            ans2[v[2]]=s[0][v[1]];
        }
        if(v.size()==2)
        {

        }

    }
}