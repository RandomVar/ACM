class Solution {
public:
    bool isMatch(string s, string p) {
        int l2=p.size();
        int match[l2+10]={0};
        int l1=s.size();
        int i=0;int j=0;
        int star=-1;
        bool flag=true;
        while(j<l2)
        {
          if(i>=l1&&p[j]!='*')
          {
            flag=false;
            break;
          }
          if(p[j]==s[i])
          {
            match[j]=i;
            i++;j++;
          }
          else if(p[j]>='a'&&p[j]<='z')
          {
            int t1=match[star+1];
            int t2=star+1;
            while(t2<=j&&t1<l1)
            {
              if(s[t1]!=p[t2]&&p[t2]!='.') 
              {
                t1++;
              }
             else{
            while(t2<=j&&t1<l1&&(s[t1]==p[t2]||p[t2]=='.'))
            {
              t1++;t2++;
            }
            }
            }
            if(t2==j+1&&t1<=l1)
            {
                i=t1;j=t2;
            }
            else {
              flag=false;break;
            }
           
          }
          else if(p[j]=='.')
          {
            match[j]=i;
            i++;j++;
          }
          else if(p[j]=='*')
          {
            match[j]=match[j-1];
            star=j;
            j++;
          }
        }
    
        if(!flag)
        return flag;
        i=l1-1;
        // cout<<star<<"star"<<endl;
        for(int j=l2-1;j>star;j--)
        {
           if(i<0||(s[i]!=p[j]&&p[j]!='.'))
           {
             flag=false;break;
           }
           i--;
            // cout<<"i"<<i<<endl;
        }
        // cout<<flag<<" "<<star<<" "<<match[star]<<endl;
        if(flag&&star>=0&&i<match[star]) flag=false;
        if(flag&&star==-1&&i>=0) flag=false;
        return flag;
    }
};