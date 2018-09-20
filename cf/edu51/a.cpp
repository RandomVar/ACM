#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   int n;
   while(cin>>n)
   {
     string s;

     for(int i=1;i<=n;i++)
     {
       int a1=0,a2=0,a3=0;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]>='a'&&s[i]<='z')
            a1++;
          if(s[i]>='A'&&s[i]<='Z')
           a2++;
           if(s[i]>='0'&&s[i]<='9')
           a3++;
        }
        if(a1==0)
        {
          // int flag=0;
          for(int i=0;i<s.size();i++)
          {
            if(a2>1&&s[i]>='A'&&s[i]<='Z')
                {s[i]='a',a2--;break;}
            if(a3>1&&s[i]>='0'&&s[i]<='9')
              {s[i]='a',a3--;break;}
          }
          a1++;
        }
        if(a2==0)
        {
          for(int i=0;i<s.size();i++)
          {
            if(a1>1&&s[i]>='a'&&s[i]<='z')
                {s[i]='A',a1--;break;}
            if(a3>1&&s[i]>='0'&&s[i]<='9')
              {s[i]='A',a3--;break;}
          }
          a2++;
        }
        if(a3==0)
        {
          for(int i=0;i<s.size();i++)
          {
            if(a1>1&&s[i]>='a'&&s[i]<='z')
                {s[i]='1',a1--;break;}
            if(a2>1&&s[i]>='A'&&s[i]<='Z')
              {s[i]='1',a2--;break;}
          }
          a3++;
        }
        cout<<s<<endl;
     }
   }
 return 0;
  }
