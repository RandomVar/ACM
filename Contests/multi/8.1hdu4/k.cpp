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
   string s;
int check()
{
    int len=s.size();
    int flag=0;
    
    for(int i=0;i<len;i++)
       {
           if(!((s[i]>='0'&&s[i]<='9')||s[i]=='*'||s[i]=='+'||s[i]=='?'))
             return 0;
           if(s[i]=='?')
           {
               if(flag==0) 
                    s[i]='1',flag=3;
                
               else if(flag==1)
                   s[i]='+',flag=2;
               // else if(flag==1)
                //  return 0;
                else if(flag==2)
                  s[i]='1',flag=3;
                else if(flag==3)
                   s[i]='1',flag=3;
           }
           else{
           if(flag==0)//begin
           {
           if(!(s[i]>='0'&&s[i]<='9')) return 0;
           if(s[i]=='0') flag=1;
           else flag=3;
           }
           else if(flag==1)// has 0
           {
             if(s[i]>='0'&&s[i]<='9') return 0;
             flag=2;
           }
           else if(flag==2)// has op
           {
               if(!(s[i]>='0'&&s[i]<='9')) return 0;
               if(s[i]=='0') flag=1;
               else flag=3;
           }
           else if(flag==3)
           {
               if(s[i]>='0'&&s[i]<='9') flag=3;
               else flag=2;
           }
       }}
       if(flag==2) return 0;
       return 1;
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>s;
      if(check()==0)
       cout<<"IMPOSSIBLE"<<endl;
       else cout<<s<<endl;
       
    }

 return 0;
  }

