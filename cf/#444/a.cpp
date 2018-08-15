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
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  string s;
  while(cin>>s){
        int len=s.size();
        if(len<=6) {cout<<"no"<<endl;continue;}
        int d=0;int flag=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]=='1'&&d<6) continue;
            else if(s[i]=='1'&&d>=6) {flag=1;break;}
            d++;

        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
       // if(len>6) cout<<"yes"<<endl;
       /*
       else{
            int flag=0;
        for(int i=0;i<len-6;i++)
          if(s[i]=='1') {flag=1;break;}
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
       }*/


  }


}
