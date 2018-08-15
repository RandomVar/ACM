#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cala[30];
int cnt[30];
void init(){
    cala[1]=1;
  for(int i=2;i<25;i++)
     cala[i]=cala[i-1]*i;
}
int main(){
   int t;//cin>>t;
   scanf("%d",&t);
    init();
   while(t--){
     int n;
     scanf("%d",&n);
     //cin>>n;
     string s;
     cin>>s;
      memset(cnt,0,sizeof(cnt));
     for(int i=0;i<s.size();i++){
         cnt[s[i]-'a']++;
     }
     int flag=0;int ans1=0;ll ans2=1;
     for(int i=0;i<26;i++){

        if(cnt[i]%2) flag++;
        if(flag>1) break;
        if(cnt[i]==0) continue;
        else if(cnt[i]>1){
        ans1+=cnt[i]/2;
        ans2*=cala[cnt[i]/2];
     }
     }
     ll ans=cala[ans1]/ans2;
     if(flag>1) printf("0\n");
     else if(n==1) printf("1\n");
    else printf("%lld\n",ans);
   }

return 0;
}
