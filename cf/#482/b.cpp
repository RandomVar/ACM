#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int cnt1[maxn];
int cnt2[maxn];
int cnt3[maxn];
int main(){
   int k;
   while(cin>>k){
        getchar();
        string s1,s2,s3;
      cin>>s1>>s2>>s3;
      int len=s1.size();
      memset(cnt1,0,sizeof(cnt1));
       memset(cnt2,0,sizeof(cnt2));
        memset(cnt3,0,sizeof(cnt3));
      for(int i=0;i<s1.size();i++){
          if(s1[i]>='a'&&s1[i]<='z') cnt1[s1[i]-'a']++;
         else cnt1[s1[i]-'A'+30]++;
      }
      for(int i=0;i<s2.size();i++){
        if(s2[i]>='a'&&s2[i]<='z') cnt2[s2[i]-'a']++;
         else cnt2[s2[i]-'A'+30]++;
      }
      for(int i=0;i<s3.size();i++){
        if(s3[i]>='a'&&s3[i]<='z') cnt3[s3[i]-'a']++;
         else cnt3[s3[i]-'A'+30]++;
      }
      int ans1=0,ans2=0,ans3=0;
      for(int i=0;i<60;i++){
          ans1=max(cnt1[i],ans1);
          ans2=max(cnt2[i],ans2);
          ans3=max(cnt3[i],ans3);
      }
     /* ans1=ans1+k;
      if(ans1>len&&(ans1-len)%2) ans1--;
      ans2=ans2+k;
      if(ans2>len&&(ans2-len)%2) ans2--;
      ans3=ans3+k;
      if(ans3>len&&(ans3-len)%2) ans3--;*/
    if(ans1==len&&k==1) ans1--;
    else ans1=min(ans1+k,len);
    if(ans2==len&&k==1) ans2--;
    else
       ans2=min(ans2+k,len);
    if(ans3==len&&k==1) ans3--;
    else
       ans3=min(ans3+k,len);
      if(ans1>ans2&&ans1>ans3) cout<<"Kuro"<<endl;
      else if(ans2>ans1&&ans2>ans3) cout<<"Shiro"<<endl;
      else if(ans3>ans1&&ans3>ans2) cout<<"Katie"<<endl;
      else cout<<"Draw"<<endl;
   }


}
