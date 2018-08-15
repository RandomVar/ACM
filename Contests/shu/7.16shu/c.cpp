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
  int t;
   cin>>t;
   while(t--)
   {
       string s1,s2;
       cin>>s1>>s2;
       int len1=s1.size();
       //int len2=s2.size();
       int cnt=0;
       int flag=1;
       for(int i=0;i<=len1/2;i++)
       {
            if(cnt%2==0)
            {
                if(s1[i]==s2[i]) continue;
                else if(s1[i]==s2[len1-i-1]){
                    cnt++;
                }
                else {flag=0;break;}
            }
            else{
                if(s1[i]==s2[len1-i-1]) continue;
                else if(s1[i]==s2[i]) cnt++;
                else {flag=0;break;}
            }
       }
      if(flag==0) cout<<-1<<endl;
    else cout<<cnt<<endl;
   }


  }

