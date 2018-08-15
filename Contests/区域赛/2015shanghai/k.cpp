#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e5+100;
ll num[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;int cas=0;
  while(t--){
        mem(num,0);
      string s;
      cin>>s;
      int k=0;int cnt=0;
      char pre=' ';
      for(int i=0;i<s.size();i++){
        if(s[i]==pre) cnt++;
          else {
            pre=s[i];
           num[++k]=cnt;
            cnt=1;
          }
      }
      if(cnt) num[++k]=cnt;

      ll ans=0;
      ll sum=0;
     // cout<<k<<endl;
   for(int i=2;i<=k;i++){
     /* if(i==index2) ans+=(ll)(num[i]+1)*(num[i]+1);
      else if(i==index1) ans+=(ll)(num[i]-1)*(num[i]-1);
      else ans+=(ll)num[i]*num[i];*/
   if(i>2) ans=max(ans,(num[i]+1)*(num[i]+1)+(num[i-1]-1)*(num[i-1]-1)-(num[i]*num[i])-(num[i-1]*num[i-1]));
   if(i<k) ans=max(ans,(num[i]+1)*(num[i]+1)+(num[i+1]-1)*(num[i+1]-1)-(num[i]*num[i])-(num[i+1]*num[i+1]));
        sum+=(ll)num[i]*num[i];
   }
   //cout<<ans<<endl;
   ll changx=0;
   for(int i=3;i<k;i++){
      if(num[i]==1){
         changx=max(changx,(num[i-1]+1+num[i+1])*(num[i-1]+1+num[i+1])-1-(num[i+1]*num[i+1])-(num[i-1]*num[i-1]));
       //   cout<<changx<<endl;
      }
   }
  //  cout<<changx<<endl;
   cout<<"Case #"<<++cas<<": ";
    cout<<sum+max(ans,changx)<<endl;
    /*  int len=0;
      char pre=' ';
      int cnt=0;
      int index=0;
      int prelen=0;
      for(int i=0;i<s.size();i++){
          if(s[i]==pre) cnt++;
          else {
            pre=s[i];
            if(cnt>len){
                len=cnt;
                index=i;
            }
            cnt=1;
          }
      }
      if(cnt>len){
          len=cnt;
          index=s.size()-1;
      }
      cout<<len<<endl;
      cnt=0;
      ll ans=0;
    for(int i=0;i<s.size();i++){

        if(s[i]==pre) cnt++;
        else  if(i==index){
            cnt++;

        }
        else
        {
            pre=s[i];
            ans+=(ll)cnt*cnt;
            cnt=1;
          }

    }
    if(cnt) ans+=(ll)cnt*cnt;
    cout<<ans<<endl;
*/
  }

}
