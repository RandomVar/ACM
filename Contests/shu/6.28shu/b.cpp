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
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   string s;
   while(cin>>s){
      for(int i=0;i<s.size();i++){
         if(s[i]=='.') s[i]=' ';
         if(s[i]=='e') s[i]=' ';

      }

      stringstream ss(s);
      int a;string b;int d;
      ss>>a;
      ss>>b;
      ss>>d;
     // cout<<a<<endl;
     if(b.size()<=d){
        if(!(a==0&&d))
           cout<<a;
        int i=0;

        while(b[i]=='0') {i++;}
          int flag=1;
        for(i;i<b.size();i++){
           cout<<b[i];
           flag=0;
        }
        if(flag==0)
        for(int i=b.size();i<d;i++){
            cout<<0;
        }
        else cout<<0;
        cout<<endl;
     }
     else{
       if(!(a==0))
            cout<<a;
            int i=0;
      while(i<d&&b[i]=='0') {i++;}

      int flag=1;
        for(i;i<d;i++)
          cout<<b[i],flag=0;
        if(flag) cout<<'0';
       cout<<".";
       for(int i=d;i<b.size();i++)
        cout<<b[i];
        cout<<endl;
     }
     // cout<<a*quickmod(10,d)<<endl;
//

   }



}
