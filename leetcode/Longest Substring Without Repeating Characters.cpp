#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int len=s.size();
      int t=0;
      int q=-1;
     int ans=0;
      int cnt[300]={0};
      while(t<len)
      {
        // cout<<"!"<<cnt[s[t]]<<endl;
        if(cnt[s[t]]==0)
           cnt[s[t]]++;
        else {
          while(q<t-1)
          {
            q++;
            cnt[s[q]]--;
            
            if(s[q]==s[t])
             {
              cnt[s[t]]++;
             break;
             }
          }
        }
         ans=max(ans,t-q);
        //  cout<<t<<" "<<q<<endl;
        t++;
      }
      return ans;
    }
};
int main()
{
  Solution sol;
  string s="abc";
  cout<<sol.lengthOfLongestSubstring(s);
  int x;
  cin>>x;

}