
class Solution {
public:
    bool isMatch(string s, string p) {
        int l2=p.size();
        int l1=s.size();
        cout<<l1<<" "<<l2<<endl;
        int flag=true;
        map<int,int>can;
        map<int,int>::iterator it,it2;
        map<int,int>::reverse_iterator rit;
        can[-1]=1;
        int j=0;
        while(j<l2)
        {
            // cout<<"j"<<j<<" i"<<i<<" q"<<q<<endl;
            if(p[j]=='.'&&j+1<l2&&p[j+1]=='*')
            {
             it=can.begin();
            if(it==can.end()) return false;
             int c=it->first+1;
             for(int i=c;i<l1;i++)
             {
               can[i]=1;
             }
                j+=2;
            }
           else
           {
             if(j+1<l2&&p[j+1]=='*')
             {  
                 int pre=l1;
              for(rit=can.rbegin();rit!=can.rend();rit++)
              {
                int c=rit->first+1;
                 cout<<j<<" "<<c<<endl;
                while(c<pre&&s[c]==p[j])
                {
                  can[c]=1;
                  c++;
                }
                  pre=rit->first+1;
              }
              j+=2;  
             }
             else 
             {
              
                for(rit=can.rbegin();rit!=can.rend();rit++)
                {
                  int c=rit->first+1;
                 cout<<"rit"<<" "<<c<<endl;
                  if(c<l1&&(s[c]==p[j]||p[j]=='.'))
                     can[c]=1;
                  // delete rit->second;
                    c=rit->first;
               
                    can[c]=0; 
                   // can.erase(rit++);
                }
                 for(it=can.begin();it!=can.end();)
                 {
                     cout<<it->first<<" "<<it->second<<"it"<<endl;
                     if(it->second==0)
                          can.erase(it++);
                     else it++;
                 }
              
              j++;
               }
           }
        }
        cout<<"can"<<can[l1-1]<<endl;
        return can[l1-1];
    
    }

};