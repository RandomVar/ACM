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
int main(){
   string s1,s2;
   while(cin>>s1>>s2){
        int ans=0;
      int len=s1.size();
      for(int i=0;i<len;i++){
          if(s1[i]=='0'&&s2[i]=='0'){
              if(s1[i+1]=='0') {
                ans++;
                s2[i+1]='X';
              }
              else if(s2[i+1]=='0'){
                 ans++;
                 s1[i+1]='X';

              }

          }
          else if(s1[i]=='0'||s2[i]=='0'){
              if(s1[i+1]=='0'&&s2[i+1]=='0')
            {
                ans++;
                s1[i+1]='X';s2[i+1]='X';
            }
          }

      }
     cout<<ans<<endl;
   }
}
