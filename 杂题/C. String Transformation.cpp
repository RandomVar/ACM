#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
vector<char>v;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  string s;
  while(cin>>s){
  int tar=0;
  v.clear();
  int len=s.size();
  for(int i=0;i<len;i++){
        //if(tar>=26) break;
      if(tar<26&&s[i]-'a'<=tar){
        v.pb(char(tar+'a'));
        tar++;
      }
      else {
        v.pb(s[i]);
      }
  }

    if(tar<26) cout<<-1<<endl;
    else {
        for(int i=0;i<v.size();i++)
            cout<<v[i];
        cout<<endl;
    }
  }


}
