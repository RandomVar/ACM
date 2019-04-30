class Solution {
public:
  
    string longestPalindrome(string s) {
        
      int len=s.size();
      char p[2*len+10];
      for(int i=0;i<len;i++)
      {
        p[2*i]=s[i];
        p[2*i+1]='#';
      }
      len=strlen(p);
      int f[len+10]={0};
   
      int mx=0;int po=0;
        
      for(int i=1;i<len;i++)
      {
         if(mx>i)
         {
           f[i]=min(f[2*po-i],mx-i);
         }
         while(i-f[i]-1>=0&&i+f[i]+1<len&&p[i-f[i]-1]==p[i+f[i]+1])
           f[i]++;
          if(mx<i+f[i])
          {
            po=i;
            mx=i+f[i];
          }
          // cout<<"f[i]"<<f[i]<<endl;
      }
      int ans=0;
      int pos=0;
      for(int i=0;i<len;i++)
      {
        if(f[i]>ans)
        {
          pos=i;
          ans=f[i];
        }
        // ans=max(ans,f[i]/2);
      }
      string str;
      for(int i=pos-ans;i<=pos+ans;i++)
         if(p[i]!='#') str+=p[i];
    return str;
    }
};