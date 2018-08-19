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
const int maxn=1e6+10;
char s[maxn];
vector<char>ans;
vector<int>vec[30];
vector<int>::iterator it;
int main(){
   // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   //cin>>t;
   scanf("%d",&t);
   while(t--)
   {
       for(int i=0;i<=26;i++)
         vec[i].clear();
         ans.clear();
       int n;
   //    cin>>n;
      int pos=0;
       scanf("%d",&n);
          scanf("%s",s);
          int len=strlen(s);
          for(int j=0;j<len;j++)
           vec[s[j]-'a'].pb(j),ans.pb(s[j]),pos++;

         for(int i=1;i<n;i++)
         {
             int flag=1;
             scanf("%s",s);
             int len=strlen(s);
             int pre=-1;
           
             for(int j=0;j<len;j++)
             {
                 if(flag)
                 {
                 it=upper_bound(vec[s[j]-'a'].begin(),vec[s[j]-'a'].end(),pre);
                 if(it==vec[s[j]-'a'].end())
                  ans.pb(s[j]),vec[s[j]-'a'].pb(pos++),flag=0;
                  else pre=(*it);
                //  cout<<pre<<endl;
                }
             else{
                 ans.pb(s[j]),vec[s[j]-'a'].pb(pos++);
             }
             }
            
         }

         len=ans.size();
         for(int i=0;i<len;i++)
          printf("%c",ans[i]);
          printf("\n");
         //cout<<ans[i];
         //cout<<endl;
   }
   
 return 0;
  }

