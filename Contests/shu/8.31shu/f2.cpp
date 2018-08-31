#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
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
int f[300];
int st[300];
string ans[1<<13];
string s;
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
  cin>>t;
  while(t--)
  {
      mem(f,0);
     
       cin>>s;
     //cout<<s;
     int k=0;
     int len=s.size();
     int top=-1;
     for(int i=0;i<len;i++)
     {
         if(s[i]=='(')
          st[++top]=i;
          else if(s[i]==')')
           {
               int zuo=st[top];
               top--;
               f[i]=(1<<k);
            f[zuo]=(1<<k);
            k++;
           }
     }
     //cout<<k<<endl;
     int kk=0;
     for(int i=1;i<(1<<k);i++)
     {
           ans[kk]="";         
         for(int j=0;j<len;j++)
         {
         if(f[j]&i) continue;
         ans[kk]+=s[j];
         }
         kk++;
     }
     sort(ans,ans+kk);
    int m=unique(ans,ans+kk)-ans;
     for(int i=0;i<m;i++)
      cout<<ans[i]<<endl;

  }
 return 0;
  }
