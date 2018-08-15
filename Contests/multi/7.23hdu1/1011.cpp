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
  // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int cas;
   scanf("%d",&cas);
   //cin>>cas;
   while(cas--)
   {
       int a,b;
       scanf("%d%d",&a,&b);
       //cin>>a>>b;
       int tt=a*60+b;
       char s[20];
       scanf("%s",s);
       //cin>>s;
       int k=0;
       int len=strlen(s);
       int t=0;
       int flag=0;
       for(int i=4;i<len;i++)
          if(!flag&&s[i]!='.')
          {
         
              t*=10;
              t+=s[i]-'0';
          }
          else if(s[i]=='.')
          {
              flag=1;
              break;
          }
        t*=60;
        if(flag) t+=(s[len-1]-'0')*6;
        if(s[3]=='-') t=-t;
       // cout<<tt<<endl;
       // cout<<t*60<<endl;
        int ans=tt+t-8*60; 
        //cout<<ans<<endl;
        if(((ans+48*60)/60)%24<10)
          printf("0");

        printf("%d:",((ans+48*60)/60)%24);
  
        if((ans+60*48)%60<10)
        printf("0");
        printf("%d\n",(ans+60*48)%60);
   }

 return 0;
  }

