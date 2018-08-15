#include<bits/stdc++.h>
using namespace std;
int cnt[10000][5];
int main(){
   string s;
   while(cin>>s){
        memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.size();i++){
        if(s[i]=='.') continue;
        cnt[i][s[i]-'A']++;
         cnt[i+1][s[i]-'A']++;
          cnt[i+2][s[i]-'A']++;
    }
    int flag=0;
    for(int i=0;i<=s.size();i++){
      if(cnt[i][0]&&cnt[i][1]&&cnt[i][2]) {flag=1;break;}
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
   }
return 0;
}
