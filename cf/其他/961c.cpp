#include<bits/stdc++.h>
using namespace std;
string s[5][110];
int cnt[5];
int main(){
   int n;
   cin>>n;
   memset(cnt,0,sizeof(cnt));
 for(int i=1;i<=4;i++){
   for(int j=0;j<n;j++)
     cin>>s[i][j];
     getchar();
     }
  for(int i=1;i<=4;i++){
      for(int j=0;j<n;j++){
          for(int k=0;k<n;k++){
               int x=(j%2)^(k%2);
               if(x!=(s[i][j][k]-'0')) cnt[i]++;
          }
      }
  }
  int ans=0;
   sort(cnt+1,cnt+5);
   for(int i=1;i<=2;i++)
      ans+=cnt[i];
   for(int i=3;i<=4;i++)
      ans+=n*n-cnt[i];
    cout<<ans<<endl;
}
