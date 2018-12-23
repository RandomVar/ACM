#include<bits/stdc++.h>
using namespace std;
int cnt[30];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len=s.size();
        int flag=0;
        for(int i=0;i<len;i++)
          if(s[i]!=s[0]) flag=1;
        memset(cnt,0,sizeof(cnt));
        if(!flag)
        {
            cout<<-1<<endl;
            continue;
        }
        flag=0;
        for(int i=0;i<len;i++)
          if(s[i]!=s[len-i-1])
            flag=1;
        if(flag)
        {
            cout<<s<<endl;
        }
        else
        {
            for(int i=0;i<len;i++)
              cnt[s[i]-'a']++;
            for(int i=0;i<26;i++)
            {
                while(cnt[i])
                 {
                     cout<<char('a'+i);
                     cnt[i]--;
                 }
            }
            cout<<endl;
        }
    }
}